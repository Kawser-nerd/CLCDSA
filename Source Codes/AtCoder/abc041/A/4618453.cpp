#include <iostream>

int main(){
    std::string s;
    int i;
    std::cin >> s >> i;

    std::cout << s.at(i - 1) << std::endl;

    return 0;
}