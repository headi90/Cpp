#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::pair<int, int>> findSumZero(const std::vector<int>& vec, int sum)
{
    std::vector<std::pair<int, int>> out;
    std::unordered_set<int> set;

    for (auto el : vec) {
        int temp = sum - el;
        if (set.find(temp) != set.end()) {
            out.push_back(std::make_pair(el, temp));
        }

        set.insert(el);
    }
    return out;
}

// not exactly working
std::vector<std::pair<int, int>> findSumZero_loops(const std::vector<int>& vec, int sum)
{
    std::vector<std::pair<int, int>> out{};

    if (vec.size() < 2) {
        return out;
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 1; j < vec.size(); ++j) {
            if ((vec[i] + vec[j]) == sum)
                out.push_back({vec[i], vec[j]});
        }
    }

    return out;
}

std::vector<std::pair<int, int>> findSumZero_sort(std::vector<int> vec, int sum)
{
    std::vector<std::pair<int, int>> out{};

    if (vec.size() < 2) {
        return out;
    }

    std::sort(vec.begin(), vec.end());

    size_t iter_begin = 0;
    size_t iter_end = vec.size() - 1;

    while (iter_begin < iter_end) {
        if ((vec[iter_begin] + vec[iter_end]) == sum) {
            out.push_back({vec[iter_begin], vec[iter_end]});
            iter_begin++;
        }
        else if ((vec[iter_begin] + vec[iter_end]) < sum) {
            iter_begin++;
        }
        else {
            iter_end--;
        }
    }

    return out;
}

template <class T>
void printPairVec(std::vector<std::pair<T, T>> vec)
{
    if (vec.empty()) {
        std::cout << "Pair not found!!\n";
    }
    for (auto& el : vec) {
        std::cout << el.first << " + " << el.second << " = " << el.first + el.second << '\n';
    }
}

template <class T>
void testFunction(std::function<std::vector<std::pair<T, T>>(const std::vector<T>&, T)> fun)
{
    std::cout << "*********************************\n";
    std::vector<T> v1{1, -1};
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    v1.clear();
    v1 = {1, 2, 3, 4, 5, 6, 7, -3, -5, -6};
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    v1.clear();
    v1 = {100, 500, 666, -789, -500, 777, 654, -777};
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    v1.clear();
    v1 = {100, 0, 200, -100, 0, 100, 999, -899};
    printPairVec<T>(fun(v1, 100));
    std::cout << "---------------------------------\n";

    v1.clear();
    v1 = {1, 2, 3, 4, 5, 6, 7};
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    v1.clear();
    v1 = {1};
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    v1.clear();
    printPairVec<T>(fun(v1, 0));
    std::cout << "---------------------------------\n";

    std::cout << "*********************************\n\n";
}

int main()
{
    testFunction<int>(findSumZero);
    testFunction<int>(findSumZero_sort);
    testFunction<int>(findSumZero_loops);
    return 0;
}