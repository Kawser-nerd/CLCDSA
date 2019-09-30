#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> vec(1, 0);
    int x = 0;
    for(int i = 0; i < n; ++i){
        if('I' == s.at(i)){
            ++x;
        }else{
            --x;
        }

        vec.push_back(x);
    }

    std::cout << *std::max_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}