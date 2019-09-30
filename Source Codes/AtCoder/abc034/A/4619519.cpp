#include <iostream>

int main(){
    int x, y;
    std::cin >> x >> y;

    if(x < y){
        std::cout << "Better" << std::endl;
    }else{
        std::cout << "Worse" << std::endl;
    }

    return 0;
}