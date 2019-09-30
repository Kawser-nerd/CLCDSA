#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }
    
    std::sort(v.begin(), v.end(), std::greater<int>());
    
    int a = 0;
    int b = 0;

    for(int i = 0; i < n; ++i){
        if(0 == i%2){
            a += v[i];
        }else{
            b += v[i];
        }
    }

    std::cout << a - b << std::endl;
}