#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(0 == b % a){
        std::cout << b / a << std::endl;
    }else{
        std::cout << b / a + 1 << std::endl;
    }

    return 0;
}