#include <iostream>

int main(){
    int r;
    std::cin >> r;

    if(r < 1200){
        std::cout << "ABC" << std::endl;
    }else if(r < 2800){
        std::cout << "ARC" << std::endl;
    }else{
        std::cout << "AGC" << std::endl;
    }

    return 0;
}