#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main(){
    int x;
    std::cin >> x;
    
    int b, p, val;
    std::vector<int> vec;
    if(1 == x){
        std::cout << 1 << std::endl;
    }else{
        for(b = 2;; ++b){
            p = 2;
            val = std::pow(b, p);
            if(val > x){
                break;
            }else{
                while(val <= x){
                    vec.push_back(val);
                    ++p;
                    val = std::pow(b, p);
                }
            }
        }

        std::cout << *max_element(vec.begin(), vec.end()) << std::endl;
    }

    return 0;
}