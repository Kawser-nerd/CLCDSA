#include <iostream>

int main(){
    int a, d;
    std::cin >> a >> d;

    if(a < d){
        ++a;
    }else{
        ++d;
    }

    std::cout << a * d << std::endl;

    return 0;
}