#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long 

char d[105][105];

int main(){
    int r,g,b;
    int H, W;
    cin >> H >> W;
    for(int i = 0; i <= H+1; i++){
        for(int j = 0; j <= W+1; j++){
            if(i == 0 || j == 0 || i == H+1 || j == W+1){
                d[i][j] = '#';
            }else{
                cin >> d[i][j];
            }
        }
    }
    for(int i = 0; i <= H+1; i++){
        for(int j = 0; j <= W+1; j++){
            cout << d[i][j];
        }
        cout << endl;
    }
}