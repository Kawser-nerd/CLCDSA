#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    int plus = a + b;
    int minus = a - b;

    if(c == plus && c == minus){
        std::cout << "?" << std::endl;
    }else if(c == plus){
        std::cout << "+" << std::endl;
    }else if(c == minus){
        std::cout << "-" << std::endl;
    }else{
        std::cout << "!" << std::endl;
    }

    return 0;
}