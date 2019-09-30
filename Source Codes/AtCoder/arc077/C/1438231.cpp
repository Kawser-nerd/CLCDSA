#include <algorithm>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<int> a(n); repeat (i, n) scanf("%d", &a[i]);
    // solve
    ll total = 0;
    vector<ll> imos0(2 * m);
    vector<ll> imos1(2 * m);
    repeat (i, n - 1) {
        int l = a[i] - 1;
        int r = a[i + 1] - 1;
        if (r < l) r += m; // [l, r] on [0, 2n)
        total += r - l;
        if (r - l <= 1) continue;
        imos0[l + 2] += 1;
        imos0[r + 1] -= 1;
        imos1[r + 1] -= (r + 1) - (l + 2);
    }
    imos1[0] += imos0[0];
    repeat (i, 2 * m - 1) {
        imos0[i + 1] += imos0[i];
        imos1[i + 1] += imos1[i] + imos0[i + 1];
    }
    vector<ll> reward(m);
    repeat (i, m) reward[i] = imos1[i] + imos1[i + m];
    ll result = total - *whole(max_element, reward);
    // output
    printf("%lld\n", result);
    return 0;
}