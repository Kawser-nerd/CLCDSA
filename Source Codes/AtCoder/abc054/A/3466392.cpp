#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if( a == b ) {
        cout << "Draw" << '\n';
        return 0;
    }
    else if( (a-2+13)%13 > (b-2+13)%13 ) {
        cout << "Alice" << '\n';
        return 0;
    }
    else {
        cout << "Bob" << '\n';
        return 0;
    }
}