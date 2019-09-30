//
// B - Between a and b ...
//

#include <iostream>

using namespace std;
using LL = long long;

int main() {
    LL a, b, x, ans;
    cin >> a >> b >> x;
    ans = b / x - a / x;
    if (a % x == 0) ans++;
    cout << ans << endl;
}