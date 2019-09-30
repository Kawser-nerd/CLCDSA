#include <iostream>

using namespace std;

int main() {
    const int z = 100001;
    int x, k, r[z], s[z], o[z], w[z], q, i;
    cin >> x;
    cin >> k;
    int v = -1;
    r[0] = w[0] = o[0] = 0;
    s[0] = x;
    for (i = 1; i <= k; i++, v *= -1) {
        cin >> r[i];
        int d = (r[i] - r[i-1]) * v;
        w[i] = min(max(w[i-1] + d, 0), x);
        s[i] = max(min(s[i-1] + d, x), 0);
        o[i] = min(o[i-1] - min(0, w[i-1] + d), x);
    }
    cin >> q;
    i = 0;
    while(q--) {
        int t, a;
        cin >> t >> a;
        if (t >= r[k]) i = k;
        else {
            int n = k;
            while (i < n - 1) {
                int c = i + (n - i) / 2;
                if (r[c] < t) i = c;
                else n = c;
            }
        }
        int ans = min(w[i] + max(a - o[i], 0), s[i]) + (t - r[i]) * ((i % 2) * 2 - 1);
        cout << min(max(ans, 0), x) << endl;
    }
}