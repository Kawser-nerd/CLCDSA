#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a>1 && b>1){
        if (a>b){
            cout << "Alice" << endl;
        }
        else if (b>a){
            cout << "Bob" << endl;
        }
        else cout << "Draw" << endl;
    }
    if (a == 1 || b == 1){
        if (b!=1){
            cout << "Alice" << endl;
        }
        else if (a!=1){
            cout << "Bob" << endl;
        }
        else cout << "Draw" << endl;
    }
}