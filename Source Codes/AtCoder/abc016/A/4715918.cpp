#include <iostream>

int main(){
    int m, d;
    std::cin >> m >> d;

    if(0 == m % d){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}