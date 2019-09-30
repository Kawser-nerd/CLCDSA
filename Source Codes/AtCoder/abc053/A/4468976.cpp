#include <iostream>

int main(){
    int x;
    std::cin >> x;

    if(x < 1200){
        std::cout << "ABC" << std::endl;
    }else{
        std::cout << "ARC" << std::endl;
    }

    return 0;
}