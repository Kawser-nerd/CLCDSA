#include <iostream>

int main(){
    int a, b, c;

    std::cin >> a >> b >> c;

    if(175 == a*b*c){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
}