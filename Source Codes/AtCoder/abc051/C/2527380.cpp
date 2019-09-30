#include<iostream>

using namespace std;

int main(){
    int sx, sy, tx, ty, diffx, diffy;
    cin >>sx >>sy >>tx >>ty;
    diffx = tx - sx;
    diffy = ty - sy;
    //1?
    for(int i = 0; i < diffx; i++){
        cout << "R";
    }
    for(int i = 0; i < diffy; i++){
        cout << "U";
    }
    //2?
    for(int i = 0; i < diffx; i++){
        cout << "L";
    }
    for(int i = 0; i < diffy; i++){
        cout << "D";
    }
    //3?
    cout << "D";
    for(int i = 0; i < diffx + 1; i++){
        cout << "R";
    }
    for(int i = 0; i < diffy + 1; i++){
        cout << "U";
    }
    cout << "L";
    //4?
    cout << "U";
    for(int i = 0; i < diffx + 1; i++){
        cout << "L";
    }
    for(int i = 0; i < diffy + 1; i++){
        cout << "D";
    }
    cout << "R";
    cout << endl;



}