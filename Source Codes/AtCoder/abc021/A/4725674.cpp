#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec;
//    std::map<int, int> binary;
    int count = 0;
    while(0 != n){
//        std::cout << std::pow(2, count++) * (n % 2) << std::endl;
        if(0 != n % 2){
            vec.push_back(std::pow(2, count) * (n % 2));
        }
        n /= 2;
        ++count;
    }
    
    std::cout << vec.size() << std::endl;
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec.at(i) << std::endl;
    }

    return 0;
}