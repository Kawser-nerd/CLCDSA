#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const ll INF = 1LL << 60;
int n, m, a, b;
ll s[5005], t[5005];
vector <int> edge[5005];
ll dp[5005][5005]; // ??i???subtree?????????j???subtree???????????????

int dfs(int cur, int par) {
    ll dp2[2][5005]; // ??x???????j???subtree?????????
    fill(dp2[0], dp2[1]+5005, INF);
    dp2[0][0] = 0;

    int sm = 1;
    int x = 0, y = 1;
    for (auto child : edge[cur]) {
        if (child == par) continue;

        int sz = dfs(child, cur);
        for (int i = 0; i < sm; i++) {
            for (int j = 0; j <= sz; j++) {
                dp2[y][i+j] = min(dp2[y][i+j], dp2[x][i] + dp[child][j]);
            }
        }

        sm += sz;
        swap(x, y);
        fill(dp2[y], dp2[y]+5005, INF);
    }

    dp[cur][0] = 0;
    for (int i = 0; i < sm; i++) {
        dp[cur][i+1] = dp2[x][i] + s[cur];
    }

    return sm;
}

int main() {
    cin >> n;
    ll sm = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sm += s[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) cin >> t[i];
    sort(t, t+m, greater<ll>());
    for (int i = 1; i < m; i++) t[i] += t[i-1];

    dfs(0, -1);

    ll ret = sm;
    for (int i = 1; i <= min(n, m); i++) {
        ret = max(ret, sm - dp[0][i] + t[i-1]);
    }

    cout << ret << "\n";
    return 0;
}