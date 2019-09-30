/**
 * A - ??
 */

#include <iostream>

using namespace std;

int main() {

    int A, B;
    cin >> A >> B;

    if (B % A) {
        if (B > A) {
            cout << (B / A) + 1 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << B / A << endl;
    }
}