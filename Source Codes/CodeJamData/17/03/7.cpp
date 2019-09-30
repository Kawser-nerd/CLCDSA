#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int solve() {
    ll n, k;
    scanf("%lld%lld", &n, &k);

    map<ll, ll> tot;
    tot[n] = 1;

    ll last = 0;
    while (k) {
        auto it = tot.end();
        --it;
        ll now = it -> ff;
        last = now;
        ll amount = min(k, it -> ss);
        tot[now] -= amount;
        tot[(now - 1) / 2] += amount;
        tot[(now - 1) - (now - 1) / 2] += amount;
        k -= amount;
        if (!tot[now]) {
            tot.erase(now);
        }
    }
 
    cout << (last - 1) - (last - 1) / 2 << " " << (last - 1) / 2 << "\n";

    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}