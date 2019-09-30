#include <algorithm>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using ll = long long;
using namespace std;

vector<int> solve(int n, ll l, ll t, vector<int> const & x, vector<int> const & w) {
    ll cnt = 0;
    repeat (i, n) if (w[0] != w[i]) {
        int dx = x[i] - x[0];
        dx = (w[0] == 1 ? dx : l - dx);
        cnt += (2 * t - dx + l) / l;
    }
    cnt %= n;
    vector<int> y(n);
    int z = 0;
    repeat (i, n) {
        y[i] = ((x[i] + (w[i] == 1 ? +1ll : -1ll) * t) % l + l) % l;
        if (y[i] == y[0]) z = i;
    }
    int y_0 = y[0];
    sort(whole(y));
    int ofs = find(whole(y), y_0) - y.begin();
    if (z and w[0] < w[z]) ++ ofs;
    int shift = (w[0] == 1 ? - cnt + ofs + n : cnt + ofs) % n;
    rotate(y.begin(), y.begin() + shift, y.end());
    return y;
}

int main() {
    int n, l, t; scanf("%d%d%d", &n, &l, &t);
    vector<int> x(n), w(n); repeat (i, n) scanf("%d%d", &x[i], &w[i]);
    vector<int> y = solve(n, l, t, x, w);
    for (int y_i : y) {
        printf("%d\n", y_i);
    }
    return 0;
}