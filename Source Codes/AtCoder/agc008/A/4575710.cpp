#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y;
    cin >> x >> y;

    ll ans;
    if (x * y == 0) {
        ans = abs(y) + abs(x) + (y < 0) + (x > 0);
    } else if (x * y < 0) {
        ans = abs(abs(y) - abs(x)) + 1;
    } else {
        if (y > x) ans = y - x;
        else ans = x - y + 2;
    }

    cout << ans << "\n";
    return 0;
}