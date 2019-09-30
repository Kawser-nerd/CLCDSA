#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;

    ll ans = o;

    ll c = min({i, j, l});
    ans += 3 * c;
    i -= c; j -= c; l -= c;

    ans += i / 2 * 2; i %= 2;
    ans += j / 2 * 2; j %= 2;
    ans += l / 2 * 2; l %= 2;

    if (i + j + l == 2 && c > 0) ans++;

    cout << ans << "\n";
    return 0;
}