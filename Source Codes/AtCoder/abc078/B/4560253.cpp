#include <iostream>

int main(){
    int x, y, z;
    std::cin >> x >> y >> z;

    int i = 1;
    while(z + i * (y + z) <= x){
        ++i;
    }

    std::cout << i - 1 << std::endl;

    return 0;
}