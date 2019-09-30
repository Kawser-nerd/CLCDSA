#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(fabs(a - c) <= d){
        cout << "Yes" << "\n";
    }
    // ??????????9ms???
    else if((fabs(a - b) <= d) && (fabs(b - c) <= d)){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }

    return 0;
}