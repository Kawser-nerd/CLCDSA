#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string buf;
    std::cin >> buf;
    std::smatch match;
    std::regex_search(buf, match, std::regex("\\d\\d?"));
    std::cout << match.str() << std::endl;
}