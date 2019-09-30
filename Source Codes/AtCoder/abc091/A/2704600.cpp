#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;
    if(A + B >= C){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }

    return 0;
}