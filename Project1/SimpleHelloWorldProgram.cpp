/**
 * @file SimpleHelloWorldProgram.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cstdio>
#include <string.h>

const int POOL_SIZE = 1024;

size_t myStrlen(const char *str)
{
    size_t len = 0;

    while (*str)
    {
        ++len;
        ++str;
    }

    return len;
}

void *myMemcpy(void *dest, const void *src, size_t n)
{
    char *destPtr = reinterpret_cast<char *>(dest);
    const char *srcPtr = reinterpret_cast<const char *>(src);

    for (size_t i = 0; i < n; ++i)
    {
        *(destPtr + i) = *(srcPtr + i);
    }

    return dest;
}

class FixedPoolAllocator
{
public:
    FixedPoolAllocator() : nextFreeBlock_(memoryPool_), numFreeBlocks_(POOL_SIZE / sizeof(FixedPoolAllocator)) {}

    void *allocate(size_t size)
    {
        if (size > sizeof(FixedPoolAllocator))
        {
            return nullptr;
        }

        if (numFreeBlocks_ <= 0)
        {
            return nullptr;
        }

        void *result = nextFreeBlock_;

        nextFreeBlock_ += size;
        numFreeBlocks_ -= size / sizeof(FixedPoolAllocator);

        return result;
    }

    void deallocate(void *ptr)
    {
        // Deallocation not supported
    }

private:

    char memoryPool_[POOL_SIZE];
    char *nextFreeBlock_;
    size_t numFreeBlocks_;
};

class String
{
public:
    String() : data_(nullptr), size_(0) {}

    void initialize(const char *str)
    {
        size_ = strlen(str);
        data_ = reinterpret_cast<char *>(allocator_.allocate(size_ + 1));
        memcpy(data_, str, size_ + 1);
    }

    ~String()
    {
        allocator_.deallocate(data_);
    }

    const char *c_str() const
    {
        return data_;
    }

private:
    char *data_;
    size_t size_;
    FixedPoolAllocator allocator_;
};

class OutputDevice
{
public:
    OutputDevice() {}

    void print(const char *str)
    {
        while (*str)
        {
            putc(*str, stdout);
            ++str;
        }
    }
};

class HelloWorld
{
public:
    void sayHello()
    {
        String message;
        message.initialize("Hello World!");
        outputDevice_.print(message.c_str());
    }

private:
    OutputDevice outputDevice_;
};

int main()
{
    FixedPoolAllocator allocator;
    HelloWorld* helloWorld = new HelloWorld();

    helloWorld->sayHello();
    helloWorld->~HelloWorld();
    allocator.deallocate(helloWorld);
    return 0;
}
