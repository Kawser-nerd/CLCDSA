#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> scores(3), people(3);
    for(int i = 0; i < 3; ++i){
        std::cin >> scores.at(i);
        people.at(i) = scores.at(i);
    }

    std::sort(scores.begin(), scores.end());
    std::reverse(scores.begin(), scores.end());

    for(int i = 0; i < 3; ++i){
        std::cout << std::distance(scores.begin(), std::find(scores.begin(), scores.end(), people.at(i))) + 1 << std::endl;
    }
}