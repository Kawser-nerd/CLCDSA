#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin >> n;

    bool flg = false;
    int i = 0;
    while(!flg){
        if(0 < n / (int)std::pow(2, i)){
            ++i;
        }else{
            flg = true;
        }
    }

    std::cout << (int)std::pow(2, i - 1) << std::endl;

    return 0;
}