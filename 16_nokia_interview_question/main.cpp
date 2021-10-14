#include <iostream>
#include <stack>
#include <string>

bool valid_braces(std::string const& s)
{
    std::stack<char> st{};

    for (auto el : s) {
        if ((el == '(') || (el == '{') || (el == '[')) {
            st.push(el);
            continue;
        }

        if (st.empty())
            return false;

        auto ch = st.top();

        if ((el == ')') && (ch == '(')) {
            st.pop();
            continue;
        }
        else if ((el == '}') && (ch == '{')) {
            st.pop();
            continue;
        }
        else if ((el == ']') && (ch == '[')) {
            st.pop();
            continue;
        }
        else {
            return false;
        }
    }

    if (st.empty())
        return true;
    return false;
}

int main()
{
    std::cout << std::boolalpha << valid_braces("(){}[]") << '\n';
    std::cout << std::boolalpha << valid_braces("({[]})[]") << '\n';
    std::cout << std::boolalpha << valid_braces("{}") << '\n';
    std::cout << std::boolalpha << valid_braces("[(])") << '\n';
    std::cout << std::boolalpha << valid_braces("[({}](]") << '\n';

    return 0;
}