#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){

    int a[3],b[3];
    int c[3][3];

    for(int i = 0; i < 3; ++i){
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }

    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(c[i][j] != a[i] + b[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}