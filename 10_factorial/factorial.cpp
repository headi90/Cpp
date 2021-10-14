#include <iostream>

long long count_factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * count_factorial(n - 1);
}

long long count_factorial_loop(int n)
{
    long long out = 1;
    for (int i = 2; i <= n; ++i) {
        out *= i;
    }
    return out;
}

int main()
{
    std::cout << count_factorial(1) << '\n';
    std::cout << count_factorial_loop(1) << '\n';
    std::cout << count_factorial(2) << '\n';
    std::cout << count_factorial_loop(2) << '\n';
    std::cout << count_factorial(3) << '\n';
    std::cout << count_factorial_loop(3) << '\n';
    std::cout << count_factorial(4) << '\n';
    std::cout << count_factorial_loop(4) << '\n';
    std::cout << count_factorial(5) << '\n';
    std::cout << count_factorial_loop(5) << '\n';
    std::cout << count_factorial(6) << '\n';
    std::cout << count_factorial_loop(6) << '\n';
    std::cout << count_factorial(7) << '\n';
    std::cout << count_factorial_loop(7) << '\n';
    std::cout << count_factorial(8) << '\n';
    std::cout << count_factorial_loop(8) << '\n';

    return 0;
}