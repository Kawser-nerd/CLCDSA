#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main(){
    int n, y;
    std::cin >> n >> y;

    std::vector<int> sum;
    std::vector<std::string> pattern;
    std::ostringstream ss1, ss2, ss3;
    std::string str;
    for(int i = 0; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            ss1.str("");
            ss2.str("");
            ss3.str("");

            sum.push_back(10000*i + 5000*(j - i) + 1000*(n - j));

            ss1 << i;
            ss2 << j - i;
            ss3 << n - j;

            str = ss1.str() + " " + ss2.str() + " " + ss3.str();

            pattern.push_back(str);
        }
    }

    std::vector<int>::iterator itr = std::find(sum.begin(), sum.end(), y);
    if(sum.end() == itr){
        std::cout << "-1 -1 -1" << std::endl;
    }else{
        int dist;
        dist = std::distance(sum.begin(), itr);
        std::cout << pattern.at(dist) << std::endl;
    }
}