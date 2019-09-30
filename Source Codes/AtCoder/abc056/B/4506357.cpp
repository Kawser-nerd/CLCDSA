#include <iostream>

int main(){
    int w, a, b;
    std::cin >> w >> a >> b;

    int ans;
    if(b < a + w){
        if(b + w < a){
            ans = a - (b + w);
        }else{
            ans = 0;
        }
    }else{
        if(a <= b && b <= a + w){
            ans = 0;
        }else{
            ans = b - (a + w);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}