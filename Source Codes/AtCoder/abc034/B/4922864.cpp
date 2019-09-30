#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int ans;
    if(1 == n % 2){
        ans = n + 1;
    }else{
        ans = n - 1;
    }

    std::cout << ans << std::endl;

    return 0;
}