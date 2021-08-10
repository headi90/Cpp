#include <algorithm>
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

// void revert_string(std::string & s){

//     auto it2=s.rbegin();
//     for(auto it = s.begin(); it != s.begin()+s.length()/2;it++, it2++){
//         *s.end() = *it;
//         *it=*it2;
//         *it2=*s.end();
//     }
//     *s.end()=0;
// }

int main()
{
    std::string s = "123456789";
    revert_string(s);
    std::cout << std::boolalpha << (s == "987654321") << '\n';

    std::string s1 = "";
    revert_string(s1);
    std::cout << std::boolalpha << (s1 == "") << '\n';

    std::string s2 = "1";
    revert_string(s2);
    std::cout << std::boolalpha << (s2 == "1") << '\n';

    std::string s4 = "12";
    revert_string(s4);
    std::cout << std::boolalpha << (s4 == "21") << '\n';

    std::string s3 = "ala";
    revert_string(s3);
    std::cout << std::boolalpha << (s3 == "ala") << '\n';

    std::string s5 = "123456789";
    std::string s6(s5.begin(), s5.end());
    revert_string(s6);
    revert_string(s6);
    std::cout << std::boolalpha << (s5 == s6) << '\n';
}
