#include <iostream>

int main(){
    int n;
    std::cin >> n;

    if(0 == n%2){
        std::cout << n << std::endl;
    }else{
        std::cout << 2*n << std::endl;
    }

    return 0;
}