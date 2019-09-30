#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int aa = a * 2;
    int bb = b * 2;
    int cc = c * 2;
    int ab = a + b;

    int xyand = min(x, y);
    unsigned long long ans = ab <= cc ? ab * xyand : cc * xyand;

    // cout << ans << endl;

    int diffX = x - xyand;
    int diffY = y - xyand;

    ans += a <= cc ? diffX * a : diffX * cc;
    // cout << ans << endl;

    ans += b <= cc ? diffY * b : diffY * cc;
    cout << ans << endl;

    return 0;
}