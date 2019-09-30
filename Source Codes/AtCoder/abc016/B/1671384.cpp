//
// B - A±B Problem
//

#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    if (A + B == C) ans += 1 << 0;
    if (A - B == C) ans += 1 << 1;
    switch (ans) {
        case 0:
            cout << '!' << endl;
            break;
        case 1:
            cout << '+' << endl;
            break;
        case 2:
            cout << '-' << endl;
            break;
        case 3:
            cout << '?' << endl;
            break;
    }
}