#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool is_palidrom(const std::string& input)
{
    for (int i = 0; i < input.length() / 2; ++i) {
        if (input[i] != input[input.length() - i - 1])
            return false;
    }
    return true;
}

bool is_palidrom_equal(const std::string& input)
{
    return std::equal(input.begin(), input.begin() + input.size() / 2, input.rbegin());
}

bool is_palidrom_mismatch(const std::string& input)
{
    return std::mismatch(input.begin(), input.end(), input.rbegin()).first == input.end();
}

//Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. Program powinien ignorować znaki specjalne jak ,.?()[], wielkość liter oraz białe znaki jak spacja czy znak nowej linii.
bool is_palindrom_insensitive(const std::string& input)
{
    std::string input_copy(input);

    input_copy.erase(std::remove_if(input_copy.begin(), input_copy.end(), [](auto character) {
                         return !std::isalpha(character) || std::isspace(character);
                     }),
                     input_copy.end());

    std::transform(input_copy.begin(), input_copy.end(), input_copy.begin(),
                   [](auto character) {
                       return std::toupper(character);
                   });

    return std::equal(input_copy.begin(), input_copy.begin() + input_copy.size() / 2, input_copy.rbegin());
}

void testFunction(std::function<bool(const std::string&)> func)
{
    std::vector<std::string> testData{
        "ala",
        "kobylamamalybok",
        "test",
        "kobyla ma maly bok",
        "abcc ba",
        "a   b   c  d!!!d??? ///c   b   a....",
        "ABCcba"};

    for (auto& testElem : testData) {
        std::cout << testElem << (func(testElem) ? " is a palindrom\n" : " is not a palindrom!\n");
    }

    std::cout << '\n';
}

int main()
{
    testFunction(is_palidrom);
    testFunction(is_palidrom_equal);
    testFunction(is_palidrom_mismatch);
    testFunction(is_palindrom_insensitive);
    return 0;
}