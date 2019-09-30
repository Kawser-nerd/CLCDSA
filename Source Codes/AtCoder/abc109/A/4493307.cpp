#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(1 == (a*b)%2){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}