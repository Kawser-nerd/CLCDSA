#include <iostream>
#include <algorithm>

int main(){
    int n, x;
    std::cin >> n >> x;

    if(x - 1 < n - x){
        std::cout << x - 1 << std::endl;
    }else{
        std::cout << n - x << std::endl;
    }

    return 0;
}