#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X;
    cin >> X;
    int max = 0;
    int temp;

    // 1???????????????????
    if(X == 1){
        max = 1;
    }
    else{
        for(int i = 2; i <= X; ++i){
            for(int j = 2; j <= X; ++j){
                temp = pow(i, j);
                if((max < temp) && (temp <= X)){
                    max = temp;
                }
                if(X < temp){
                    continue;
                }
            }
        }
    }
    cout << max << "\n";

    return 0;
}