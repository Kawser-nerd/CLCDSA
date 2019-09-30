#include <iostream>

int main(){
    int x, a, b;
    std::cin >> x >> a >> b;

    if(x < b - a){
        std::cout << "dangerous" << std::endl;
    }else if(0 >= b - a){
        std::cout << "delicious" << std::endl;
    }else{
        std::cout << "safe" << std::endl;
    }

    return 0;
}