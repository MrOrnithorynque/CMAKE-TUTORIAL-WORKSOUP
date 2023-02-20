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
            void print();
        private:
            std::string _str;
    };

    class AAAAAAAAAAAAAAA
    {
        public:
            AAAAAAAAAAAAAAA() = default;
            ~AAAAAAAAAAAAAAAA() = default;
            void print();
        private:
            std::string _str;
    };
} // namespace IsThatANamespaceExclamationMark
