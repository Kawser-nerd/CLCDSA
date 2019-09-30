#include <iostream>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    std::cout << 700 + 100*std::count(str.begin(), str.end(), 'o') << std::endl;

    return 0;
}