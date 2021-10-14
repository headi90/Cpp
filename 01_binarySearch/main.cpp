#include <algorithm>
#include <iostream>
#include <vector>

size_t binarySearch(const std::vector<int>& v, int x)
{
    size_t l = 0;
    size_t h = v.size() - 1;
    size_t m, i = 0;

    while (l <= h) {
        std::cout << "iter: " << ++i << '\n';
        m = l + (h - l) / 2;
        if (v[m] == x)
            return m;

        if (x > v[m])
            l = m + 1;
        else if (x < v[m])
            h = m - 1;
    }
    return -1;
}

size_t binarySearchRec(const std::vector<int>& v, int x, size_t l, size_t h)
{
    if (l <= h) {
        size_t m = l + (h - l) / 2;
        if (v[m] == x)
            return m;

        if (x > v[m])
            l = m + 1;
        else if (x < v[m])
            h = m - 1;

        return binarySearchRec(v, x, l, h);
    }
    return -1;
}

int main()
{
    std::vector<int> v{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::sort(v.begin(), v.end());

    std::cout << binarySearch(v, 20) << std::endl;
    std::cout << binarySearchRec(v, 20, 0, v.size() - 1) << std::endl;
    return 0;
}
