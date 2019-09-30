#include <iostream>

int main(){
    long long a,b,c,d;
    std::cin >> a >> b >> c >> d;
    long long res = a * b > c * d ? a * b : c * d;
    std::cout << res;
}