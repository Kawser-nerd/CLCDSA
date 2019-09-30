#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    std::cout << *s.begin() << s.size() - 2 << *(s.end() - 1) << std::endl;

    return 0; 
}