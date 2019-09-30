#include <iostream>

int main(){
    int n, a, b;
    std::cin >> n >> a >> b;

    int buf = n * a;
    if(buf <= b){
        std::cout << buf << std::endl;
    }else{
        std::cout << b << std::endl;
    }

    return 0;
}