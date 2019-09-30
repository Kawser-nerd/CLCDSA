#include<iostream>
#include <string>
using namespace std;

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double takahashi, aoki;
    takahashi = b/a;
    aoki = d/c;
    if (takahashi > aoki){
        cout << "TAKAHASHI" << endl;
    }
    else if (aoki > takahashi){
        cout << "AOKI" << endl;
    }
    else cout << "DRAW" << endl;
    return 0;
}