#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    if(b - a == c - b){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}