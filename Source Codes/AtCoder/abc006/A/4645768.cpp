#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int ans = 0;
    bool flg = false;
    while(n != 0){
        if(3 == n % 10){
            flg = true;
            break;
        }else{
            ans += n % 10;
            n = n / 10;
        }
    }

    if(flg){
        std::cout << "YES" << std::endl;
    }else if(0 == ans % 3){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}