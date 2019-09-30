#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string W;
    std::cin >> W;
    int size = W.size();
    bool check =false;
    int counter = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(W[i] == W[j]){
                counter++;
                if(counter%2 == 0){
                    check = true;
                }
                else{
                    check = false;
                }
            }
        }
        if(!check){
            break;
        }
    }
    if(!check){
        std::cout << "No";
    }
    else{
        std::cout << "Yes";
    }
    return 0;
}