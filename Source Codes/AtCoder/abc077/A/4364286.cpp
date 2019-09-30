#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    char C[3][3];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> C[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        if(C[0][i] != C[1][2-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" <<endl;
}