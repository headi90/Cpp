#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void print_string(std::string& s)
{
    for (size_t i = 0; i < s.length() + 1; ++i)
        std::cout << static_cast<int>(s[i]) << ' ';
    std::cout << '\n';
}

void revert_string(std::string& s)
{
    for (size_t i = 0; i < s.length() / 2; ++i) {
        s[s.length()] = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = s[s.length()];
    }
    s[s.length()] = 0;
}

void revert_string_xor(std::string& string_to_revert)
{
    size_t len = string_to_revert.length();
    for (size_t i = 0; i < len / 2; ++i) {
        string_to_revert[len - i - 1] ^= string_to_revert[i];
        string_to_revert[i] ^= string_to_revert[len - i - 1];
        string_to_revert[len - i - 1] ^= string_to_revert[i];
    }
}

void revert_string_stl(std::string& string_to_revert)
{
    std::reverse(string_to_revert.begin(), string_to_revert.end());
}

void revert_string_iter(std::string& string_to_revert)
{
    auto start = string_to_revert.begin();
    auto end = string_to_revert.end();
    end--;

    if (start == end)
        return;

    while (start < end) {
        std::iter_swap(start, end);
        start++;
        end--;
    }
}

void revert_string_c(char* string_to_revert, size_t size)
{
    if (!string_to_revert)
        return;

    for (int i = 0; i < (size - 1) / 2; ++i) {
        string_to_revert[size - 1] = string_to_revert[i];
        string_to_revert[i] = string_to_revert[size - 2 - i];
        string_to_revert[size - 2 - i] = string_to_revert[size - 1];
    }
    string_to_revert[size - 1] = 0;
}

void revert_string_c_xor(char* string_to_revert, size_t size)
{
    if (!string_to_revert)
        return;

    for (int i = 0; i < (size - 1) / 2; ++i) {
        string_to_revert[i] ^= string_to_revert[size - 2 - i];
        string_to_revert[size - 2 - i] ^= string_to_revert[i];
        string_to_revert[i] ^= string_to_revert[size - 2 - i];
    }
}

// void revert_string(std::string & s){

//     auto it2=s.rbegin();
//     for(auto it = s.begin(); it != s.begin()+s.length()/2;it++, it2++){
//         *s.end() = *it;
//         *it=*it2;
//         *it2=*s.end();
//     }
//     *s.end()=0;
// }

// void check_function(void (*fun)(std::string&))
void check_function(std::function<void(std::string&)> fun)
{
    std::string s = "123456789";
    fun(s);
    std::cout << std::boolalpha << (s == "987654321") << '\n';

    std::string s1 = "";
    fun(s1);
    std::cout << std::boolalpha << (s1 == "") << '\n';

    std::string s2 = "1";
    fun(s2);
    std::cout << std::boolalpha << (s2 == "1") << '\n';

    std::string s4 = "12";
    fun(s4);
    std::cout << std::boolalpha << (s4 == "21") << '\n';

    std::string s3 = "ala";
    fun(s3);
    std::cout << std::boolalpha << (s3 == "ala") << '\n';

    std::string s5 = "123456789";
    std::string s6(s5.begin(), s5.end());
    fun(s6);
    fun(s6);
    std::cout << std::boolalpha << (s5 == s6) << '\n';
}

int main()
{
    check_function(revert_string);
    check_function(revert_string_xor);
    check_function(revert_string_stl);
    check_function(revert_string_iter);

    // version with c-string

    // char test[] = "123456789";
    // size_t string_size = sizeof(test) / sizeof(*test);
    // std::cout << test << ' ' << string_size << '\n';
    // revert_string_c(test, string_size);
    // std::cout << test << ' ' << string_size << '\n';

    // char test2[] = "123456789";
    // size_t string_size2 = sizeof(test2) / sizeof(*test2);
    // std::cout << test2 << ' ' << string_size2 << '\n';
    // revert_string_c_xor(test2, string_size2);
    // std::cout << test2 << ' ' << string_size2 << '\n';
}
