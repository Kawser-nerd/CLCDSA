#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> players(3);
    for(int i = 0; i < 3; ++i){
        std::cin >> players.at(i);
    }

    int i = 0;
    int j;
    while(!players.at(i).empty()){
        j = (int)players.at(i).at(0) - 97;
        players.at(i).erase(players.at(i).begin());
        i = j;
    }

    std::cout << (char)(i + 65) << std::endl;
}