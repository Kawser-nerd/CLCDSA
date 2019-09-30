#include <iostream>

int main(){
    long n;
    std::cin >> n;

    int nBuf = n;
    int val = 0;
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