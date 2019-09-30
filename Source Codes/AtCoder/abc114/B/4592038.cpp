#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    int val;
    std::vector<int> vec;
    for(int i = 1; i < str.size() - 1; ++i){
        vec.push_back(abs(std::stoi(str.substr(i - 1, 3)) - 753));
    }
    
    std::sort(vec.begin(), vec.end());

    std::cout << *vec.begin() << std::endl;

    return 0;
}