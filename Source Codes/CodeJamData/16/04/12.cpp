#include <iostream>

using namespace std;

typedef long long ll;

int t;
int k, c, s;

void solve(int x) {
    cin >> k >> c >> s;
    cout << "Case #" << x << ":";
    if (s*c < k) {
        cout << " IMPOSSIBLE\n";
        return;
    }
    int u = 0;
    int e = k;
    while (e > 0) {
        ll t = 0;
        ll z = 1;
        for (int i = 0; i < c; i++) {
            if (u < k) u++;
            t += (u-1)*z;
            z *= k;
            e--;
        }
        cout << " " << t+1;
    }
    cout << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
