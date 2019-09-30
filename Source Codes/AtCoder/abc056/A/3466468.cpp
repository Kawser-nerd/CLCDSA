#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;

    if( (a == 'H' && b == 'H') || (a == 'D' && b == 'D') ) {
        cout << 'H' << '\n';
        return 0;
    }
    else {
        cout << 'D' << '\n';
        return 0;
    }
}