#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string ans = "No";

    if (abs(c - a) <= d) {
        ans = "Yes";
    }

    if ((abs(b - a) <= d) && (abs(c - b) <= d)) {
        ans = "Yes";
    }

    cout << ans << endl;
    return 0;
}