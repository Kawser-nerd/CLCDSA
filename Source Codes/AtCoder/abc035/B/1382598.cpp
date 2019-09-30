#include <iostream>
#include <cstdlib>
std::string S;
int T;

int main(void){
    std::cin >> S;
    std::cin >> T;

    int x=0, y=0, cnt=0;
    for(auto it=S.begin(), _END = S.end(); it != _END; ++it){
        if(*it == 'L'){
            --x;
        }else if(*it == 'R'){
            ++x;
        }else if(*it == 'U'){
            ++y;
        }else if(*it == 'D'){
            --y;
        }else if(*it == '?'){
            ++cnt;
        }
    }

    if(T == 1){
        std::cout << abs(x) + abs(y) + cnt << std::endl;
    }else{
        int ans = abs(x) + abs(y) - cnt;
        if(ans >= 0){
            std::cout << ans << std::endl;
        }else{
            std::cout << abs(ans)%2 << std::endl;
        }
    }
}