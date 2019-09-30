#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 210;
const int INF = 1000000000;
const int Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-8;

int next[N];
char s[N], ch[N];
int K, L, n;
double dp[N][N][N];
bool f[N][N][N];

void get_next() {
    int i = 0, j = -1;
    next[0] = -1;
    while(i < L) {
        if(j == -1 || s[i] == s[j]) {
            i ++; j ++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int go[N][30];

int _go(int k, char cc) {
    if(go[k][cc - 'A'] != -1) return go[k][cc - 'A'];
    int j = k;
    while(j != -1 && s[j] != cc) {
        j = next[j];
    }
    return go[k][cc - 'A'] = j + 1;
}

void solve() {
    scanf("%d%d%d", &K, &L, &n);
    scanf("%s%s", ch, s);
    get_next();
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    memset(go, -1, sizeof(go));

    dp[0][0][0] = 1; f[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < L; j++) {
            for(int o = 0; o < i; o++) {
                if(!f[i - 1][o][j]) continue;
                for(int k = 0; k < K; k++) {
                    int t = _go(j, ch[k]);
                    if(t == L) {
                        dp[i][o + 1][next[t]] += dp[i - 1][o][j] / K;
                        f[i][o + 1][next[t]] = 1;
                    }
                    else {
                        dp[i][o][t] += dp[i - 1][o][j] / K;
                        f[i][o][t] = 1;
                    }
                }
            }
        }
    }
    int tot = 0;
    for(int i = 0; i < L; i++) {
        for(int j = 0; j <= n; j++) {
            if(f[n][j][i]) {
                tot = max(tot, j);
            }
        }
    }
    double ans = tot;
    for(int i = 0; i < L; i++) {
        for(int j = 0; j <= n; j++) {
            ans -= dp[n][j][i] * j;
        }
    }
    printf("%.8f\n", ans);

}

int main() {
    freopen("B2.in", "r", stdin);
    freopen("B2.out", "w", stdout);  
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
