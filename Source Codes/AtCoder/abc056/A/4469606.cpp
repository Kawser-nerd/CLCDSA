#include <iostream>

int main(){
    char a, b;
    std::cin >> a >> b;

    if('H' == a){
        if('H' == b){
            std::cout << 'H' << std::endl;
        }else{
            std::cout << 'D' << std::endl;
        }
    }else{
        if('H' == b){
            std::cout << 'D' << std::endl;
        }else{
            std::cout << 'H' << std::endl;
        }
    }

    return 0;
    
}