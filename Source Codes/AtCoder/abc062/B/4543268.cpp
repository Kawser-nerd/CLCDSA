#include <iostream>
#include <vector>

int main(){
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> line(h);
    for(int i = 0; i < h; ++i){
        std::cin >> line.at(i);
    }

    std::string boundary(w + 2, '#');

    std::cout << boundary << std::endl;
    for(int i = 0; i < h; ++i){
        std::cout << '#' << line.at(i) << '#' << std::endl;
    }
    std::cout << boundary << std::endl;

    return 0;
}