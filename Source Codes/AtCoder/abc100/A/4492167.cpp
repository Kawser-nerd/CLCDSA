#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if(a < 9 && b < 9){
        std::cout << "Yay!" << std::endl;
    }else{
        std::cout << ":(" << std::endl;
    }

    return 0;
}