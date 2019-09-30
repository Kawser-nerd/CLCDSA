#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int count = 0;
    int dividable;
    for(int i = 0; i <= (n - 1) / 2; ++i){
        dividable = 0;
        for(int j = 1; j <= n; ++j){
            if(0 == (2 * i + 1) % j){
                ++dividable;
            }
        }

        if(8 == dividable){
            ++count;
        }

    }

    std::cout << count << std::endl;

    return 0;
}