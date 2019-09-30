#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;

    int a, b;
    std::vector<std::vector<int>> roads(2 * m, std::vector<int>(2));
    std::vector<int> road(2);
    for(int i = 0; i < m; ++i){
        std::cin >> a >> b;
        road.at(0) = a;
        road.at(1) = b;
        roads.at(i) = road;
        road.at(0) = b;
        road.at(1) = a;
        roads.at(i + m) = road;
    }

//    std::sort(roads.begin(), roads.end());
//    roads.erase(std::unique(roads.begin(), roads.end()), roads.end());

    int counter;
    for(int i = 1; i <= n; ++i){
        counter = 0;
        for(int j = 0; j < roads.size(); ++j){
            if(i == roads.at(j).at(0)){
                ++counter;
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}