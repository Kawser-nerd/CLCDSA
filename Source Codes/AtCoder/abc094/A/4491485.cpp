#include <iostream>

int main(){
    int a, b, x;
    std::cin >> a >> b >> x;

    if(a <= x && x <= a + b){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}