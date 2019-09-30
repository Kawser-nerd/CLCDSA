#include <iostream>
#include <map>
#include <vector>
#include <numeric>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a;
    int val;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        if(0 != val){
            a.push_back(val);
        }
    }

    int sum = std::accumulate(a.begin(), a.end(), 0);

    if(0 != sum % a.size()){
        std::cout << sum / a.size() + 1 << std::endl;
    }else{
        std::cout << sum / a.size() << std::endl;
    }

    return 0;
}