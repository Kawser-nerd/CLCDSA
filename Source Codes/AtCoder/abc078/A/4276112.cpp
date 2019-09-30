#include <iostream>
using namespace std;


int main() {
    char x, y, ans;
    cin >> x >> y;

    if ( x < y ) {
        ans = '<';
    }
    else if ( x > y ) {
        ans = '>';
    }
    else {
        ans = '=';
    }

    cout << ans << endl;
    return 0;
}