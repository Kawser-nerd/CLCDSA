#include <iostream>

int main(){
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;

    int ans;
    if(a1 < b1){
        if(a2 < b1){
            ans = 0;
        }else if(a2 <= b2){
            ans = a2 - b1;
        }else{
            ans = b2 - b1;
        }
    }else if(b1 < a1){
        if(b2 < a1){
            ans = 0;
        }else if(b2 <= a2){
            ans = b2 - a1;
        }else{
            ans = a2 - a1;
        }
    }else{
        if(a2 < b2){
            ans = a2 - a1;
        }else{
            ans = b2 - a1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}