#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        char c;
        cin >> c;
        ans += (c == '+' ? 1 : -1);
    }

    cout << ans << endl;
}