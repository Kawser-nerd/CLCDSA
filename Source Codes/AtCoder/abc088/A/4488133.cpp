#include <iostream>

int main(){
    int n, a;
    std::cin >> n >> a;

    if(a >= n - n/500*500){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}