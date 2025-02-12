#include <iostream>

struct DontCopyMe {
    int resultA;
    int resultB;

    DontCopyMe() = default;
    DontCopyMe(const DontCopyMe& other)
        : resultA(other.resultA)
        , resultB(other.resultB)
    {
        std::cout << "Please don't copy me\n";
    }
};

int main()
{
    DontCopyMe collection[10];

    for (int i = 0; i < 10; ++i) {
        collection[i].resultA = i;
        collection[i].resultB = 2 * i;
    }

    int resultA = 0;
    int resultB = 0;
    for (auto const& item : collection) {
        resultA += item.resultA;
        resultB += item.resultB;
    }
    std::cout << "resultA = " << resultA << "\tresultB = " << resultB << "\n";

    return 0;
}
