#include <iostream>

using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int startRemainder = a % b;
    // bool canSelect = false;

    for (int i = 2; ;i++) {
        if (startRemainder == (a * i) % b) {
            cout << "NO" << endl;
            break;
        } else if ((a * i) % b == c) {
            cout << "YES" << endl;
            break;
        }
    }

    return 0;
}