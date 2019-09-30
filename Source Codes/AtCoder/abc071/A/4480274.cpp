#include <iostream>

int main(){
    int x, a, b;
    std::cin >> x >> a >> b;

    int da = abs(x - a);
    int db = abs(x - b);
    
    if(da < db){
        std::cout << "A" << std::endl;
    }else{
        std::cout << "B" << std::endl;
    }

    return 0;
}