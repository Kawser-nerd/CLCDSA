#include <iostream>

using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int startRemainder = a % b;
    bool canSelect = false;

    for (int i = 2; ;i++) {
        if (startRemainder == (a * i) % b) {
            break;
        } else if ((a * i) % b == c) {
            canSelect = true;
        }
    }

    if (canSelect) cout << "YES" << endl;
    else           cout << "NO" << endl;

    return 0;
}