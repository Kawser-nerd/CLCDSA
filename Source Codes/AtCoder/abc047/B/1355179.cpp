#include <iostream>
using namespace std;

int main(){
    int W, H, N;
    cin >> W >> H >> N;

    int X[N], Y[N], A[N];
    for(int i = 0; i < N; ++i){
        cin >> X[i] >> Y[i] >> A[i];
    }

    int left = 0, right = W, up = H, down = 0;
    int total = right * up;
    for(int i = 0; i < N; ++i){
        switch(A[i]){
            case 1:
                if(left < X[i]) left = X[i];
                break;
            case 2:
                if(right > X[i]) right = X[i];
                break;
            case 3:
                if(down < Y[i]) down = Y[i];
                break;
            case 4:
                if(up > Y[i]) up = Y[i];
                break;
        }
    }
        
    cout << (max(0, right - left))*(max(0, up - down)) << endl;

    return 0;
}