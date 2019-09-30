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
    ll x;
    cin >> x;

    ll ans = x / 11 * 2;
    x %= 11;

    if (x > 6) ans += 2;
    else if (x > 0) ans += 1;

    cout << ans << "\n";
    return 0;
}