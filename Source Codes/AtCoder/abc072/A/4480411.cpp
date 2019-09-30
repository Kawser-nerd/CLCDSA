#include <iostream>

int main(){
    int x, t;
    std::cin >> x >> t;

    int rem = x - t;
    if(rem < 0){
        std::cout << 0 << std::endl;
    }else{
        std::cout << rem << std::endl;
    }

    return 0;
}