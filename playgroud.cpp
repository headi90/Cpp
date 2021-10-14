#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
// std::vector<int> findOddOccuringElement(const std::vector<int>& inputVector)
// {
//     std::vector<int> result{};
//     std::unordered_map<int, int> map;
//     for (auto el : inputVector) {
//         map[el]++;
//     }

//     for (auto& [key, value] : map) {
//         if (value % 2 != 0) {
//             result.push_back(key);
//         }
//     }

//     return result;
// }

// std::vector<int> findEvenOccuringElement(const std::vector<int>& inputVector)
// {
//     std::vector<int> result{};
//     std::unordered_map<int, int> map;
//     for (auto el : inputVector) {
//         map[el]++;
//     }

//     for (auto& [key, value] : map) {
//         if (value % 2 == 0) {
//             result.push_back(key);
//         }
//     }

//     return result;
// }

// template <class T>
// void printVector(const std::vector<T>& vec)
// {
//     for (auto el : vec) {
//         std::cout << el << ' ';
//     }
//     std::cout << '\n';
// }

// int countingValleys(int steps, std::string path)
// {
//     std::vector<int> recalc{};
//     int numberOfValleys{};

//     std::transform(path.begin(), path.end(), std::back_inserter<recalc>, [](char el) {
//         if (el == 'U')
//             return 1;
//         if (el == 'D')
//             return -1;
//         return 0;
//     });

//     int sum{};
//     for (int i = 0; i < steps; ++i) {
//         int prev_sum = sum;
//         sum += recalc[i];
//         if (prev_sum >= 0 && sum < 0) {
//             numberOfValleys++;
//         }
//     }

//     return numberOfValleys;
// }

// How to block objects creation on stack?
class A {
public:
    int a;
    ~A() = delete;
};

class B {
public:
    int b;
};

class BaseIn {
public:
    BaseIn()
    {
        std::cout << "BaseIn C-tor\n";
    }
    ~BaseIn()
    {
        std::cout << "BaseIn D-tor\n";
    }
};

class Base {
public:
    Base(const std::string& whatToPrint)
        : whatToPrint_(whatToPrint)
    {
        std::cout << "Base C-tor\n";
    }
    ~Base()
    {
        std::cout << "Base D-tor\n";
    }
    virtual void print() const = 0;

protected:
    std::string whatToPrint_ = {};
    BaseIn Bi;
};

class DerrivedIn {
public:
    DerrivedIn()
    {
        std::cout << "DerrivedIn C-tor\n";
    }
    ~DerrivedIn()
    {
        std::cout << "DerrivedIn D-tor\n";
    }
};

class Derrived : public Base {
public:
    Derrived()
    // : Base("Dummy")
    {
        std::cout << "Derrived C-tor\n";
    }
    ~Derrived()
    {
        std::cout << "Derrived D-tor\n";
    }
    void print() const override
    {
        std::cout << "Derrived print: " << whatToPrint_ << "\n";
    };

    DerrivedIn Di;
};

int main()
{
    // std::vector<int> test1{1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 3, 5};

    // printVector<int>(findOddOccuringElement(test1));
    // printVector<int>(findEvenOccuringElement(test1));

    // A a;

    Base* base;
    Derrived der;

    der.print();

    base = &der;

    base->print();

    Base& baseRef = der;

    baseRef.print();

    int* tab = new int[10];

    for (int i = 0; i < 10; ++i)
        tab[i] = i;

    for (int i = 0; i < 10; ++i)
        std::cout << tab[i] << ' ';
    std::cout << '\n';

    delete[] tab;

    auto objTab = new B[10];
    for (int i = 0; i < 10; ++i)
        objTab[i].b = i + 10;

    for (int i = 0; i < 10; ++i)
        std::cout << objTab[i].b << ' ';
    std::cout << '\n';

    delete[] objTab;

    //polymorphism

    return 0;
}