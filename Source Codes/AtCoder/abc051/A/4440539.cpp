#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    s.at(5) = ' ';
    s.at(13) = ' ';

    std::cout << s << std::endl;

    return 0;
}