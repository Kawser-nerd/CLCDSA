#include <iostream>
#include <vector>

int main(){
    int n, a, b;
    std::cin >> n >> a >> b;

    int numerator, buf;
    std::vector<int> vec;
    for(int i = 1; i <= n; ++i){
        buf = 0;
        numerator = i;
        if(i < 10){
            buf = i;
        }else{
            while(0 != numerator){
                buf += numerator % 10;
                numerator = numerator / 10;
            }
        }
        vec.push_back(buf);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        // std::cout << "i = " << i + 1 << ": " << vec.at(i) << std::endl;
        if(a <= vec.at(i) && vec.at(i) <= b){
            ans += i + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}