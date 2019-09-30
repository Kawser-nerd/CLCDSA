#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int four = 0;
    int remnant;
    bool flg = false;
    if(7 == n){
        flg = true;
    }else{
        while(four <= n){
            four += 4;
            remnant = n - four;
            if(0 == remnant % 7){
                flg = true;
                break;
            }
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}