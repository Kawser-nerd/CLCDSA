#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    long a, b, k;
    std::cin >> a >> b >> k;

    std::vector<long> ans;
    if(b - a + 1 > k){
        for(long i = 0; i < k; ++i){
            ans.push_back(a + i);
            ans.push_back(b - i);
        }
    }else{
        for(int i = a; i <= b; ++i){
            ans.push_back(i);
        }
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    for(int i = 0; i < ans.size(); ++i){
        std::cout << ans.at(i) << std::endl;
    }

    return 0;
}