#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int c[3][3]; 
    bool flag = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    int b1, b2, b3;
    b1 = c[0][0], b2 = c[1][0], b3 = c[2][0];
    if(c[0][1] - b1 == c[1][1] - b2 &&  c[2][1] - b3 == c[1][1] - b2){
        if(c[0][2] - b1 == c[1][2] - b2 &&  c[2][2] - b3 == c[1][2] - b2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
}