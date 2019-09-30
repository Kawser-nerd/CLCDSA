#include <iostream>

int main(){
    int n, k;
    std::cin >> n >> k;

    if(0 == n%k){
        std::cout << 0 << std::endl;
    }else{
        std::cout << 1 << std::endl;
    }

    return 0;
}