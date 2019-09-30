#include <iostream>
#include <cmath>

int main(){
    long n;
    std::cin >> n;

    long val = 0;    
    long nBuf = n;
    while(0 != nBuf){
        val += nBuf % 10;
        nBuf = nBuf / 10;
    }

    if(0 == n % val){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}