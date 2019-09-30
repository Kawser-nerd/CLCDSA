#include <iostream>
#include <vector>

int main(){
    long a, b;
    std::cin >> a >> b;

    int diff = b - a;
    int val = 0;
    for(long i = 1; i <= diff; ++i){
        val += i;
    }

    std::cout << val - b << std::endl;

    return 0;
}