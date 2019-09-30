#include <iostream>

int main(){
    int n, k, x, y;
    std::cin >> n >> k >> x >> y;

    int fee = 0;
    if(n > k){
        fee += k*x;
        fee += (n - k)*y;
    }else{
        fee += n*x;
    }
    std::cout << fee << std::endl;
}