#include <iostream>

int main(){
    int d;
    std::cin >> d;

    std::cout << "Christmas";
    for(int i = 0; i < 25 - d; ++i){
        std::cout << " Eve";
    }

    std::cout << std::endl;

    return 0;
}