#include <iostream>

int main(){
    int k, s;
    std::cin >> k >> s;

    int val;
    int counter = 0;
    for(int x = 0; x <= k; ++x){
        for(int y = 0; y <= k; ++y){
            val = s - x - y;
            if(0 <= val && val <= k){
               ++counter;
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}