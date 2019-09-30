#include <iostream>
#include <string>
#include <array>

int main(){
    int N,K,X,Y;
    std::cin >> N >> K >> X >> Y;
    int sum;
    for(int i = 1; i < N+1; i++){
        if(i <= K){
            sum += X;
        }
        else if(i > K){
            sum += Y;
        }
    }
    std::cout << sum;
    return 0;
}