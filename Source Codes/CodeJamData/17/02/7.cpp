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
    ll n;
    scanf("%lld", &n);

    ll tmp = n;
    vector<int> num;
    while (tmp) {
        num.puba(tmp % 10);
        tmp /= 10;
    }

    reverse(bend(num));

    ll ans = 1;

    bool flag = true;
    for (int i = 0; i < szof(num) - 1; ++i) {
        flag &= num[i] <= num[i + 1];
    }

    if (flag) {
        ans = n;
    }

    for (int i = 0; i < szof(num); ++i) {
        bool flag = true;
        for (int j = 0; j + 1 < i; ++j) {
            flag &= num[j] <= num[j + 1];
        }
        if (i) {
            flag &= num[i - 1] <= num[i] - 1;
        }
        if (flag) {
            ll cur = 0;
            for (int j = 0; j < i; ++j) {
                cur = cur * 10 + num[j];
            }
            cur = cur * 10 + num[i] - 1;
            for (int j = i + 1; j < szof(num); ++j) {
                cur = cur * 10 + 9;
            }
            ans = max(ans, cur);
        }
    }

    cout << ans << "\n";

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