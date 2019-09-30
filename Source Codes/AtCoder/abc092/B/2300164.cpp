#include <iostream>

int main(){
    int Chocolate;
    int N,D,X;
    std::cin >> N >> D >> X;
    int array[N];
    int i=0, j=0;
    for(i=0;i<N; i++){std::cin >> array[i];}

    for(i=0;i<N; i++) {
        Chocolate = 0;
        for(j=1;j<D+1; j=j+array[i]) {
            Chocolate++; 
        }
        X += Chocolate;
    }
    std::cout << X << std::endl;  
}