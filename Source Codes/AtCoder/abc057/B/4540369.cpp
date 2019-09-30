#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;

    long x, y;
    std::vector<std::vector<long>> students(n, std::vector<long>(2));
    for(int i = 0; i < n; ++i){
        std::cin >> x >> y;
        students.at(i).at(0) = x;
        students.at(i).at(1) = y;
    }

    std::vector<std::vector<long>> points(m, std::vector<long>(2));
    for(int i = 0; i < m; ++i){
        std::cin >> x >> y;
        points.at(i).at(0) = x;
        points.at(i).at(1) = y;
    }

    std::vector<long> distance(m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            distance.at(j) = abs(students.at(i).at(0) - points.at(j).at(0)) + abs(students.at(i).at(1) - points.at(j).at(1));
        }

        std::cout << std::distance(distance.begin(), std::min_element(distance.begin(), distance.end())) + 1 << std::endl;
    }

    return 0;
}