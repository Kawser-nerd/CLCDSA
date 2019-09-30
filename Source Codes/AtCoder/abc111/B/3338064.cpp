#include <iostream>
int main(){
    unsigned int n;
    std::cin >> n;
    n -= 1;
    std::cout << (n - (n % 111 + 1) + 112);
}