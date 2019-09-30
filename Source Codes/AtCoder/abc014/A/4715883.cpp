#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(0 == a % b){
        std::cout << 0 << std::endl;        
    }else{
        std::cout << b - (a % b) << std::endl;
    }

    return 0;
}