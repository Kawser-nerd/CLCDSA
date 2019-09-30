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
const int MAXN = 1e6 + 5;

char buf[MAXN];
int here[MAXN];

int solve() {
    int sz;
    scanf("%s%d", buf, &sz);

    int n = strlen(buf);

    fill(here, here + n, 0);
    int bal = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bal -= here[i];
        if ((buf[i] == '-') != (bal & 1)) {
            if (i + sz > n) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            bal++;
            here[i + sz]++;
            ++ans;
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