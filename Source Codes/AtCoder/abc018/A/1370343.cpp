#include <iostream>
using namespace std;


int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(A > B){
        if(B < C){
            if(A > C) cout << 1 << endl << 3 << endl << 2 << endl;
            else cout << 2 << endl << 3 << endl << 1 << endl;
        }else{
            cout << 1 << endl << 2 << endl << 3 << endl;
        }
    }else{
        if(B < C){
            cout << 3 << endl << 2 << endl << 1 << endl;
        }else{
            if(A > C) cout << 2 << endl << 1 << endl << 3 << endl;
            else cout << 3 << endl << 1 << endl << 2 << endl;
        }
    }
    
    return 0;
}