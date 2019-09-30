#include <iostream>

int main(){
    long long a, b, x;
    std::cin >> a >> b >> x;

    if(0 == a){
        std::cout << b/x + 1 << std::endl;
    }else{
        std::cout << b/x - (a - 1)/x << std::endl;
    }

    return 0;
}