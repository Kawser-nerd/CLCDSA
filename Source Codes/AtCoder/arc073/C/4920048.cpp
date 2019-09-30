#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll x[n], y[n];
    ll mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] < y[i]) swap(x[i], y[i]);
        mn = min(mn, y[i]);
        mx = max(mx, x[i]);
    }

    // Rmax = mx, Bmin = mn ??
    ll Bmax = 0, Rmin = 1e9;
    for (int i = 0; i < n; i++) {
        Rmin = min(Rmin, x[i]);
        Bmax = max(Bmax, y[i]);
    }
    ll ans = (mx - Rmin) * (Bmax - mn);

    // Rmax = mx, Rmin = mn ??
    priority_queue <P, vector<P>, greater<P>> q;

    ll Bmin = 1e9;
    Bmax = 0;
    for (int i = 0; i < n; i++) {
        Bmin = min(Bmin, y[i]);
        Bmax = max(Bmax, y[i]);
        q.push(P(y[i], i));
    }
    ans = min(ans, (mx - mn) * (Bmax - Bmin));


    while (true) {
        P p = q.top();
        q.pop();

        if (p.first < x[p.second]) {
            q.push(P(x[p.second], p.second));

            Bmin = q.top().first;
            Bmax = max(Bmax, x[p.second]);
            ans = min(ans, (mx - mn) * (Bmax - Bmin));
        } else {
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}