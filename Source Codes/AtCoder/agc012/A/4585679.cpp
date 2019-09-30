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

    int n;
    cin >> n;
    int a[3*n];
    for (int i = 0; i < 3*n; i++) cin >> a[i];

    sort(a, a+3*n, greater<int>());

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        ans += a[i*2+1];
    }

    cout << ans << "\n";
    return 0;
}