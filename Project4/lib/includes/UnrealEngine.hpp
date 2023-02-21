#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace IsThatANamespaceExclamationMark
{
    class VeryInterestingClass
    {
        public:
            VeryInterestingClass() = default;
            ~VeryInterestingClass() = default;
            virtual void print();
        private:
            std::string _str;
    };

    class AAAAAAAAAAAAAAA
    {
        public:
            AAAAAAAAAAAAAAA() = default;
            ~AAAAAAAAAAAAAAA() = default;

            void BeginPlay();

        private:
            std::string _str;
    };

    class String : public std::string
    {
        public:
            String() = default;
            ~String() = default;

            virtual std::string zdeftgrNNOOOOOOOOON(std::string str);

        private:
            std::string _str;
    };
} // namespace IsThatANamespaceExclamationMark
