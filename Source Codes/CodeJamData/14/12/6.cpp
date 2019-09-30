#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int f[MAXN][MAXN];
bool z[MAXN][MAXN];
int S[MAXN];
vector<int> x[MAXN];

int dp(int a, int fa) {
    if (z[a][fa]) return f[a][fa];
    z[a][fa] = true;
    f[a][fa] = 0;
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == fa) continue;
        f[a][fa] += S[x[a][i]];
    }
    
    int ans1 = 2000, ans2 = 2000;
    int SS = 0;
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == fa) continue;
        SS += S[x[a][i]];
    }
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == fa) continue;
        for (int j = i + 1; j < x[a].size(); ++j) {
            if (x[a][j] == fa) continue;
            int temp = dp(x[a][i], a) + dp(x[a][j], a) + SS - S[x[a][i]] - S[x[a][j]];
            f[a][fa] = min(f[a][fa], temp);
        }
    }
    return f[a][fa];
}


int dfsS(int a, int fa) {
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == fa) continue;
        S[a] += dfsS(x[a][i], a);
    }
    ++S[a];
    return S[a];
}

int main() {
    int T, N;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        cin >> N;
        for (int i = 1; i <= N; ++i) x[i].clear();
        for (int i = 1; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            x[a].push_back(b);
            x[b].push_back(a);
        }
        int ans = 2000;
        for (int i = 1; i <= N; ++i) {
            memset(f, -1, sizeof(f));
            memset(z, 0, sizeof(z));
            memset(S, 0, sizeof(S));
            dfsS(i, 0);
            ans = min(ans, dp(i, 0));
        }
        cout << "Case #" << times << ": " << ans << endl;
    }
    return 0;
}
