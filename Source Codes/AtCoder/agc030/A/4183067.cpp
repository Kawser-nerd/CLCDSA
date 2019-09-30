#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b) < c) {
        cout << a + (2 * b) + 1 << endl;
    } else {
        cout << b + c << endl;
    }
    
    return 0;
}