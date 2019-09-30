#include <iostream>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if((abs(a - b) <= d && abs(b - c) <= d) || abs(c - a) <= d){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    } 
}