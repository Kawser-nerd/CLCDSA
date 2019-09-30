#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(10 <= a + b){
        std::cout << "error" << std::endl;
    }else{
        std::cout << a + b << std::endl;
    }

    return 0;
}