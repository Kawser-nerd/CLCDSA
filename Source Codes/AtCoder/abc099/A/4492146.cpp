#include <iostream>

int main(){
    int n;
    std::cin >> n;

    if(n < 1000){
        std::cout << "ABC" << std::endl;
    }else{
        std::cout << "ABD" << std::endl;
    }
}