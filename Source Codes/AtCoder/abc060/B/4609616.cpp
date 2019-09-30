#include <iostream>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    bool flg = false;
    for(int i = 1; i <= b; ++i){
        if(c == (i * a) % b){
            flg = true;
            break;
        }
    }

    if(flg){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}