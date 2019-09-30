#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(1 == a){
        a = 14;
    }

    if(1 == b){
        b = 14;
    }

    if(a > b){
        std::cout << "Alice" << std::endl;
    }else if(b > a){
        std::cout << "Bob" << std::endl;
    }else{
        std::cout << "Draw" << std::endl;
    }

    return 0;
}