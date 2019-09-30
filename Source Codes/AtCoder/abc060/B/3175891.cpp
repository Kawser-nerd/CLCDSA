#include <iostream>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;

    bool flag = false;
    for (int i = 1; i <= b; ++i) {
        flag = a * i % b == c;
        if (flag) break;
    }

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}