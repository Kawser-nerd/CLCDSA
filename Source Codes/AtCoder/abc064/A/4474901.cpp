#include <iostream>
#include <string>
#include <sstream>

int main(){
    std::string r, g, b;
    std::cin >> r >> g >> b;

    std::stringstream ss;
    int rgb;
    std::string buf = r + g + b;
    ss << buf;
    ss >> rgb;

    if(0 == rgb%4){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}