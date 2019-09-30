#include <iostream>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    std::cout << std::count(str.begin(), str.end(), '+') - std::count(str.begin(), str.end(), '-') << std::endl;
}