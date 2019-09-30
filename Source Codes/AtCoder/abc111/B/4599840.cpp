#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> digits;

    bool flg = false;
    int buf, i;
    for(i = n; i <= 999; ++i){
        buf = i;
        digits.resize(3);
        for(int j = 0; j < 3; ++j){
            digits.at(j) = buf % 10;
            buf = buf / 10;
        }

        std::sort(digits.begin(), digits.end());
        digits.erase(std::unique(digits.begin(), digits.end()), digits.end());

        if(1 == digits.size()){
            flg = true;
            break;
        }
    }

    std::cout << i << std::endl;

    return 0;
}