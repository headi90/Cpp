#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <class T>
void printVector(const std::vector<T>& v)
{
    for (const auto el : v) {
        std::cout << el << " | ";
    }
    std::cout << '\n';
}

std::vector<int> findNotRepeatingElements(const std::vector<int>& v)
{
    std::vector<int> result{};

    std::map<int, int> m;
    for (auto el : v) {
        m[el]++;
    }

    for (const auto& [key, value] : m) {
        if (value == 1) {
            result.push_back(key);
        }
    }

    return result;
}

/* Driver code */
int main()
{
    std::vector<int> vec{};
    std::cout << "vec1:\n";
    printVector<int>(findNotRepeatingElements(vec));

    std::cout << "vec2:\n";
    std::vector<int> vec2{2, 3, 7, 9, 11, 2, 3, 11};
    printVector<int>(findNotRepeatingElements(vec2));

    std::cout << "vec3:\n";
    std::vector<int> vec3{1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7};
    printVector<int>(findNotRepeatingElements(vec3));
}