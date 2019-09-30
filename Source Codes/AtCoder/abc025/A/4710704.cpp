#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());

    int n;
    std::cin >> n;

    std::vector<std::string> vec(25, "");
    int i = 0;
    for(int j = 0; j < 5; ++j){
        for(int k = 0; k < 5; ++k){
            vec.at(i).push_back(s.at(j));
            vec.at(i++).push_back(s.at(k));
        }
    }

    std::cout << vec.at(n - 1) << std::endl;

    return 0;
}