#include <iostream>

long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    std::cout << (0) << " ---> " << fibonacci(0) << '\n';
    std::cout << (1) << " ---> " << fibonacci(1) << '\n';
    std::cout << (2) << " ---> " << fibonacci(2) << '\n';
    std::cout << (3) << " ---> " << fibonacci(3) << '\n';
    std::cout << (4) << " ---> " << fibonacci(4) << '\n';
    std::cout << (5) << " ---> " << fibonacci(5) << '\n';
    std::cout << (6) << " ---> " << fibonacci(6) << '\n';
    std::cout << (7) << " ---> " << fibonacci(7) << '\n';
    std::cout << (8) << " ---> " << fibonacci(8) << '\n';
    std::cout << (9) << " ---> " << fibonacci(9) << '\n';
    std::cout << (10) << " ---> " << fibonacci(10) << '\n';
    std::cout << (11) << " ---> " << fibonacci(11) << '\n';
    std::cout << (12) << " ---> " << fibonacci(12) << '\n';
    std::cout << (13) << " ---> " << fibonacci(13) << '\n';
    std::cout << (14) << " ---> " << fibonacci(14) << '\n';
    std::cout << (15) << " ---> " << fibonacci(15) << '\n';
    std::cout << (16) << " ---> " << fibonacci(16) << '\n';
    return 0;
}