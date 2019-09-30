#include <iostream>

int main(){
    int x;
    std::cin >> x;

    if(7 == x || 5 == x || 3 == x){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}