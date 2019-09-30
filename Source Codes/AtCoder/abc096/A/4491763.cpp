#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(a <= b){
        std::cout << a << std::endl;
    }else{
        std::cout << a - 1 << std::endl;
    }

    return 0;
}