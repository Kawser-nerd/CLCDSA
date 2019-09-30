#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for(int i = 0; i < n; ++i){
        std::cin >> s.at(i);
    }

    std::vector<std::string> list = s;
    std::sort(list.begin(), list.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::map<int, std::string> people;
    for(int i = 0; i < list.size(); ++i){
        people.emplace(std::count(s.begin(), s.end(), list.at(i)), list.at(i));
    }
     
    std::map<int, std::string>::iterator itr = people.end();
    --itr;
    std::cout << itr -> second << std::endl;

    return 0;
}