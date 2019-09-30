#include <iostream>

int main(){
    float n;
    std::cin >> n;

    float mean = 0;
    for(float i = 1; i <= n; ++i){
        mean += i * 10000;
    }

    std::cout << mean / n << std::endl;

    return 0;
}