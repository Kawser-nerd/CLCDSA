#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool flag = false;
    for (int i = 0; i <= n / 4; i++) {
        if ((n - 4 * i) % 7 == 0) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}