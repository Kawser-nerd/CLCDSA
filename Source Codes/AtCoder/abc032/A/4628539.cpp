#include <iostream>

int main(){
    int a, b, n;
    std::cin >> a >> b >> n;

    int i;
    for(i = n;; ++i){
        if(0 == i % a && 0 == i % b){
            break;
        }
    }

    std::cout << i << std::endl;

    return 0;
}