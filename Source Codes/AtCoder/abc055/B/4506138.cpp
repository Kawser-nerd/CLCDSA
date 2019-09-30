#include <iostream>
#include <cmath>

int main(){
    long long n;
    std::cin >> n;

    long long ans = 1;
    for(long long i = 1; i <= n; ++i){
        ans *= i%(long long)(std::pow(10, 9) + 7);
        ans = ans%(long long)(std::pow(10, 9) + 7);
    }

    std::cout << ans << std::endl;;

    return 0;
}