#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> color;
    int buf;
    for(int i = 0; i < 3; ++i){
        std::cin >> buf;
        color.push_back(buf);
    }

    std::sort(color.begin(), color.end());
    color.erase(std::unique(color.begin(), color.end()), color.end());

    std::cout << color.size() << std::endl;
}