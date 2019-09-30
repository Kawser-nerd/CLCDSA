#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, X;
    cin >> A >> B >> X;

    if((X - A < 0) || (A > X) || (A + B < X)){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
    }

    return 0;
}