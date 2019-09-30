#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx-sx;
    int dy = ty-sy;

    for(int i=0;i<dy;i++){
        cout << "U";
    }
    for(int i=0;i<dx;i++){
        cout << "R";
    }
    for(int i=0;i<dy;i++){
        cout << "D";
    }
    for(int i=0;i<dx;i++){
        cout << "L";
    }
    cout << "LU";
    for(int i=0;i<dy;i++){
        cout << "U";
    }
    for(int i=0;i<dx;i++){
        cout << "R";
    }
    cout << "RDR";
    for(int i=0;i<dy;i++){
        cout << "D";
    }
    cout << "DL";
    for(int i=0;i<dx;i++){
        cout << "L";
    }
    cout << "U" << endl;

    return 0;
}