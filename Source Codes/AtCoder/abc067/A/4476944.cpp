#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    int rem1 = a%3;
    int rem2 = b%3;
    int rem3 = (a + b)%3;

    std::string ans;
    if(0 == rem1 * rem2 * rem3){
        ans = "Possible";
    }else{
        ans = "Impossible";
    }

    std::cout << ans << std::endl;
    
    return 0;
}