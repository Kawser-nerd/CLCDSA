#include<iostream>
using namespace std;

int main() {
    int x, k, q, r[100000], t, y;
    cin >> x >> k;
    for(int i = 0; i < k; i++) cin >> r[i];
    cin >> q;
    int a{0}, b{x}, c{0}, s{0}, u{0}, v{-1};
    auto f = [](int m, int z, int n) { return max(m, min(n, z)); };
    while(q--) {
        cin >> t >> y;
        for(; u < k && r[u] <= t; s = r[u++], v *= -1) {
            c = f(-b, c + (r[u] - s) * v, x - a);
            a = f(a, 0 - c, b);
            b = f(a, x - c, b);
        }
        cout << f(0, f(a, y, b) + c + (t - s) * v, x) << endl;
    }
    return 0;
}