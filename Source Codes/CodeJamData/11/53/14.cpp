#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

char S[128][128];
vector<int> A[128*128];
int N;

int mymod(int a, int b)
{
    return (a % b + b) % b;
}

bool vis[128*128];

int powmod(int a, int b, int mod)
{
    if (b == 0)
        return 1 % mod;
    int r = powmod(a, b >> 1, mod);
    r = (long long)r * r % mod;
    if (b & 1)
        r = (long long)r * a % mod;
    return r;
}

void dfs(int a)
{
    vis[a] = true;
    for (int i = 0; i < A[a].size(); i++) {
        int b = A[a][i];
        if (!vis[b]) {
            dfs(b);
        }
    }
}

int solve()
{
    memset(vis, false, sizeof(vis));
    while (true) {
        bool found = false;
        for (int i = 0; i < N; i++)
            if (!vis[i] && A[i].size() == 1) {
                int j = A[i][0];
                int num = 0;
                for (int k = 0; k < A[j].size(); k++)
                    if (A[j][k] != i)
                        A[j][num++] = A[j][k];
                A[j].resize(num);
                vis[i] = true;
                found = true;
            }
        if (!found)
            break;
    }
    for (int i = 0; i < N; i++)
        if (!vis[i] && A[i].size() != 2)
            return 0;
    int cycles = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i])
            continue;
        vis[i] = true;
        cycles ++;
        dfs(A[i][0]);
    }
    return powmod(2, cycles, 1000003);
}

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", S[i]);
        for (int i = 0; i < n * m; i++)
            A[i].clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int dx, dy;
                if (S[i][j] == '|') {
                    dx = 1;
                    dy = 0;
                } else if (S[i][j] == '-') {
                    dx = 0;
                    dy = 1;
                } else if (S[i][j] == '\\') {
                    dx = 1;
                    dy = 1;
                } else {
                    dx = 1;
                    dy = -1;
                }
                int x1 = mymod(i + dx, n);
                int y1 = mymod(j + dy, m);
                int x2 = mymod(i - dx, n);
                int y2 = mymod(j - dy, m);
                A[x1 * m + y1].push_back(x2 * m + y2);
                A[x2 * m + y2].push_back(x1 * m + y1);
            }
        N = n * m;
        int ans = solve();
        printf("Case #%d: %d\n", ++cas, ans);
    }
}
