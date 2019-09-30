#include <iostream>
#include <sstream>
#include <cmath>

int main(){
    std::string a, b;
    std::cin >> a >> b;

    std::stringstream ss;
    ss << a + b;
    int val;
    ss >> val;

    if(0 == std::fmod(std::sqrt(val), 1)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}