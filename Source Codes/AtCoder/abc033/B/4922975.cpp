#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> towns(n);
    std::vector<int> people(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> towns.at(i);
        std::cin >> people.at(i);
        sum += people.at(i);
    }

    std::string ans = "atcoder";
    for(int i = 0; i < n; ++i){
        if(sum / 2 < people.at(i)){
            ans = towns.at(i);
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}