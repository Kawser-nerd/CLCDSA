#include <iostream>
#include <vector>

int main(){
    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> b(m);
    for(int i = 0; i < m; ++i){
        std::cin >> b.at(i);
    }

    int counter = 0;
    int buf;
    int a;
    for(int i = 0; i < n; ++i){
        buf = c;
        for(int j = 0; j < m; ++j){
            std::cin >> a;
            buf += a * b.at(j);
        }

        if(buf > 0){
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}