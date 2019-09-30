#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main(){
    int m;
    std::cin >> m;

    std::string vv;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0');
    if(m < 100){
        vv = "00";
    }else{
        if(m <= 5000){
            ss << std::to_string(m / 100);
        }else if(m <= 30000){
            ss << std::to_string(m / 1000 + 50);
        }else if(m <= 70000){
            ss << std::to_string((((m / 1000) - 30) / 5) + 80);
        }else{
            ss << std::to_string(89);
        }
        vv = ss.str();
    }

    std::cout << vv << std::endl;

    return 0;
}