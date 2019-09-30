#include <iostream>

int main(){
    int n;
    std::cin >> n;

    if(n < 60){
        std::cout << "Bad" << std::endl;
    }else if (n < 90){
        std::cout << "Good" << std::endl;
    }else if (n < 100){
        std::cout << "Great" << std::endl;
    }else{
        std::cout << "Perfect" << std::endl;
    }

    return 0;
}