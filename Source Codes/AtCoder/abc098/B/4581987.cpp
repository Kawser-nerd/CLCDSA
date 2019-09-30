#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string left, right;
    int count;
    std::vector<int> vec(n - 1);
    for(int i = 1; i < n; ++i){
        left = s.substr(0, i);
        right = s.substr(i, n - i);
        std::sort(left.begin(), left.end());
        left.erase(std::unique(left.begin(), left.end()), left.end());
        std::sort(right.begin(), right.end());
        right.erase(std::unique(right.begin(), right.end()), right.end());

        count = 0;

        for(int j = 0; j < left.size(); ++j){
            for(int k = 0; k < right.size(); ++k){
                if(left.at(j) == right.at(k)){
                    ++count;
                }
            }
        }

        vec.push_back(count);
    }

    std::cout << *max_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}