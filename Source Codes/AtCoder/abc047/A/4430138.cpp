#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    if(a == b + c){
        std::cout << "Yes" << std::endl;
    }else if(b == c + a){
        std::cout << "Yes" << std::endl;
    }else if(c == a + b){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}