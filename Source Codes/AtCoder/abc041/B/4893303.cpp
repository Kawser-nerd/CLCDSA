#include <iostream>

int main(){
    long long a, b, c;
    std::cin >> a >> b >> c;

    long long x = 1;
    x = (x * a) % 1000000007;
    x = (x * b) % 1000000007;
    x = (x * c) % 1000000007;

    std::cout << x << std::endl;

    return 0;
}