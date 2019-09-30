#include <iostream>

int main(){
    int n, a, b;
    std::cin >> n >> a >> b;

    if(1 == n){
        std::cout << "Hello World" << std::endl;
    }else{
        std::cout << a + b << std::endl;
    }

    return 0;
}