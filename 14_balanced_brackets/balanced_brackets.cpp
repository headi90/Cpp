#include <iostream>
#include <stack>
using namespace std;

bool isCharOpenBracket(const char c)
{
    return (c == '(' || c == '[' || c == '{');
}

bool isCharCloseBracket(const char c)
{
    return (c == ')' || c == ']' || c == '}');
}

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (auto el : expr) {
        // skip not bracket characters
        if (!isCharOpenBracket(el) && !isCharCloseBracket(el)) {
            continue;
        }

        if (isCharOpenBracket(el)) {
            // Push the element in the stack
            s.push(el);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (el) {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver code
int main()
{
    string expr = "{()}[]";
    cout << expr << " is " << (areBracketsBalanced(expr) ? "balanced" : "NOT balanced") << '\n';

    expr = "{(abc)rrr}rrr[rrrr]rr";
    cout << expr << " is " << (areBracketsBalanced(expr) ? "balanced" : "NOT balanced") << '\n';

    expr = "{(abc)rrr}rrr[rrrr";
    cout << expr << " is " << (areBracketsBalanced(expr) ? "balanced" : "NOT balanced") << '\n';

    return 0;
}