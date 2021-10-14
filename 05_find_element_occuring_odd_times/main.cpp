#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <vector>

template <class T>
void printVector(const std::vector<T>& v)
{
    // static_assert(std::is_arithmetic_v<T>);
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
        if ((value % 2) != 0) {
            result.push_back(key);
        }
    }

    return result;
}

std::vector<int> findElementsOccuringOddTimesHashMap(const std::vector<int>& v)
{
    std::vector<int> result{};

    std::unordered_map<int, int> m;
    for (auto el : v) {
        m[el]++;
    }

    for (const auto& [key, value] : m) {
        if ((value % 2) != 0) {
            result.push_back(key);
        }
    }

    return result;
}

// Bad one
std::vector<int> findElementsOccuringOddTimesLoops(const std::vector<int>& v)
{
    std::vector<int> result{};

    for (int i = 0; i < v.size(); ++i) {
        size_t counter = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (v[i] == v[j])
                ++counter;
        }
        if ((counter % 2) != 0)
            result.push_back(v[i]);
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

std::vector<int> findElementsOccuringOddTimesLoops2(const std::vector<int>& v)
{
    std::vector<int> result{};

    for (int i = 0; i < v.size(); ++i) {
        size_t counter = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (v[i] == v[j])
                ++counter;
        }
        if ((counter % 2) != 0 && (std::find(result.begin(), result.end(), v[i]) == result.end()))
            result.push_back(v[i]);
    }
    return result;
}

// Worst solution
std::vector<int> findElementsOccuringOddTimesLoops3(const std::vector<int>& v)
{
    std::vector<int> result{};

    for (int i = 0; i < v.size(); ++i) {
        size_t counter = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (v[i] == v[j])
                ++counter;
        }

        // check if element wasn,t already added to the result
        bool flag = false;
        for (auto el : result) {
            if (el == v[i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        if ((counter % 2) != 0) {
            result.push_back(v[i]);
        }
    }
    return result;
}

std::vector<int> findElementsOccuringOddTimesLoopsSort(const std::vector<int>& v)
{
    std::vector<int> input(v.begin(), v.end());
    std::vector<int> result{};

    std::sort(input.begin(), input.end());

    for (int i = 0; i < v.size() - 1; ++i) {
        size_t counter = 0;
        if (v[i] == v[i + 1]) {
            counter++;
        }
        else {
            if ((counter % 2) != 0)
                result.push_back(v[i]);
        }
    }
    return result;
}

std::vector<int> findElementsOccuringOddTimesLoopsSet(const std::vector<int>& v)
{
    std::set<int> resultSet{};

    for (int i = 0; i < v.size(); ++i) {
        size_t counter = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (v[i] == v[j])
                ++counter;
        }
        if ((counter % 2) != 0)
            resultSet.insert(v[i]);
    }

    return std::vector<int>(resultSet.begin(), resultSet.end());
}

/* Driver code */
int main()
{
    std::vector<int> vec = {1};
    std::cout << "vec1:\n";
    printVector<int>(findNotRepeatingElements(vec));
    printVector<int>(findElementsOccuringOddTimesLoops(vec));
    printVector<int>(findElementsOccuringOddTimesLoops2(vec));
    printVector<int>(findElementsOccuringOddTimesLoopsSet(vec));
    printVector<int>(findElementsOccuringOddTimesHashMap(vec));
    printVector<int>(findElementsOccuringOddTimesLoops3(vec));
    printVector<int>(findElementsOccuringOddTimesLoopsSort(vec));

    std::cout << "vec2:\n";
    std::vector<int> vec2{2, 3, 7, 9, 11, 2, 3, 11};
    printVector<int>(findNotRepeatingElements(vec2));
    printVector<int>(findElementsOccuringOddTimesLoops(vec2));
    printVector<int>(findElementsOccuringOddTimesLoops2(vec2));
    printVector<int>(findElementsOccuringOddTimesLoopsSet(vec2));
    printVector<int>(findElementsOccuringOddTimesHashMap(vec2));
    printVector<int>(findElementsOccuringOddTimesLoops3(vec2));
    printVector<int>(findElementsOccuringOddTimesLoopsSort(vec2));

    std::cout << "vec3:\n";
    std::vector<int> vec3{1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7};
    printVector<int>(findNotRepeatingElements(vec3));
    printVector<int>(findElementsOccuringOddTimesLoops(vec3));
    printVector<int>(findElementsOccuringOddTimesLoops2(vec3));
    printVector<int>(findElementsOccuringOddTimesLoopsSet(vec3));
    printVector<int>(findElementsOccuringOddTimesHashMap(vec3));
    printVector<int>(findElementsOccuringOddTimesLoops3(vec3));
    printVector<int>(findElementsOccuringOddTimesLoopsSort(vec3));

    std::cout << "vec4:\n";
    std::vector<int> vec4{1, 2, 3, 4, 5, 5, 5};
    printVector(findNotRepeatingElements(vec4));
    printVector(findElementsOccuringOddTimesLoops(vec4));
    printVector(findElementsOccuringOddTimesLoops2(vec4));
    printVector(findElementsOccuringOddTimesLoopsSet(vec4));
    printVector(findElementsOccuringOddTimesHashMap(vec4));
    printVector(findElementsOccuringOddTimesLoops3(vec4));
    printVector(findElementsOccuringOddTimesLoopsSort(vec4));

    std::cout << "vecTestPrint1:\n";
    std::vector<double> vecTestPrint1{1.0, 2.4, 5.5, 6.6};
    printVector<double>(vecTestPrint1);

    std::cout << "vecTestPrint2:\n";
    std::vector<char> vecTestPrint2{'a', 'b', 'c'};
    printVector(vecTestPrint2);

    std::cout << "vecTestPrint2:\n";
    std::vector<std::string> vecTestPrint3{"123", "ala", "ma", "kota"};
    printVector(vecTestPrint3);
}