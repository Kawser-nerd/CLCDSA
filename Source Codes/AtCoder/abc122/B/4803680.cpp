#include <iostream>
#include <stdio.h>

int main() {
    std::string S;
    std::cin >> S;
    int count = 0;
    int maxi = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] == 'A' || S[i] == 'T' || S[i] == 'C' ||S[i] == 'G' ){
            count++;
            if(maxi < count){
                maxi = count;
            }
        }else {
            count = 0;
        }
    }
    std::cout << maxi;
    return 0;
}