#include<iostream>

int main()
{
    std::string s;
    std::cin >> s;
    int counter = 0;
    if(s[0] == '1') ++counter;
    if(s[1] == '1') ++counter;
    if(s[2] == '1') ++counter;

    std::cout << counter << std::endl;
}