#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        std::cin >> vec.at(i);
    }
    vec.resize(2 * n);
    for(int i = 0; i < n; ++i){
        vec.at(i + n) = vec.at(i);
    }

    bool flg = true;
    int sum;
    for(int i = 0; i < n; ++i){
        sum = std::accumulate(vec.begin() + i + 1, vec.begin() + i + n, 0);
        
        if(vec.at(i) >= sum){
            flg = false;
            break;
        }
    }

    if(flg){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}