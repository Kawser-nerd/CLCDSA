#include <iostream>
#include <vector>
int main(){
    int n;
    std:: cin >> n;
    std::vector<std::string> data;
    std::string input;
    while(std::cin >> input)data.push_back(input);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout << data[(-j+n-1)][(i)];
        }
        std::cout << std::endl;
    }
}