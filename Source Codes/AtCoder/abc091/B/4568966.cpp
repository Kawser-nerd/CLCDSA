#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> dict(n);
    std::vector<std::string> s(n);
    for(int i = 0; i < n; ++i){
        std::cin >> s.at(i);
        dict.at(i) = s.at(i);
    }

    int m;
    std::cin >> m;
    std::vector<std::string> t(m);
    for(int i = 0; i < m; ++i){
        std::cin >> t.at(i);
        dict.push_back(t.at(i));
    }

    std::sort(dict.begin(), dict.end());
    dict.erase(std::unique(dict.begin(), dict.end()), dict.end());

    std::vector<int> scores(dict.size(), 0);
    for(int i = 0; i < dict.size(); ++i){
        scores.at(i) += std::count(s.begin(), s.end(), dict.at(i));
        scores.at(i) -= std::count(t.begin(), t.end(), dict.at(i));
    }

    int ans = *std::max_element(scores.begin(), scores.end());
    if(ans > 0){
        std::cout << ans << std::endl;
    }else{
        std::cout << 0 << std::endl;
    }

    return 0;
}