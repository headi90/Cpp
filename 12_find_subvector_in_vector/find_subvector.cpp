#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

bool find_subvector(const std::vector<int>& vec, const std::vector<int>& sub)
{
    return std::search(vec.begin(), vec.end(), sub.begin(), sub.end()) != vec.end();
}

bool find_subvector_loop(const std::vector<int>& vec, const std::vector<int>& sub)
{
    int j = 0;
    for (int i = 0; (i < vec.size()) && (j < sub.size()); ++i) {
        if (vec[i] == sub[j])
            j++;
        else
            j = 0;
    }
    return (j == sub.size()) ? true : false;
}

void testFunction(std::function<bool(const std::vector<int>&, const std::vector<int>&)> func)
{
    std::vector<int> vec1{1, 2, 3, 4, 5, 6};
    std::vector<int> sub1{3, 4};
    std::cout << std::boolalpha << func(vec1, sub1) << '\n';
    std::cout << std::boolalpha << func({1, 2, 3, 4, 5, 6, 7}, {1, 2}) << '\n';
    std::cout << std::boolalpha << func({1, 2, 3, 4, 5, 6, 7}, {1, 2, 3}) << '\n';
    std::cout << std::boolalpha << func({1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7, 8}) << '\n';
    std::cout << std::boolalpha << func({1, 2, 3, 4, 5, 6, 7}, {1, 3}) << '\n';

    std::cout << "**********************************\n\n";
}

int main()
{
    testFunction(find_subvector);
    testFunction(find_subvector_loop);
    return 0;
}