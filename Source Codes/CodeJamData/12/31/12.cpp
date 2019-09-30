
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <bitset>
using namespace std;

int T, n, m;
bool g[1001][1001];
int cnt[1001];
int s[1001], top;

bitset<1001> r[1001], t;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> T;
    t.reset();
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n;
        memset(g, 0, sizeof(g));
        memset(cnt, 0, sizeof(cnt));
        
        for (int u = 0; u < n; ++u) {
            r[u].reset();
            r[u][u] = 1;
            cin >> m;
            for (int i = 0; i < m; ++i) {
                int v;
                scanf("%d", &v);
                g[u][v - 1] = 1;
                cnt[v - 1]++;
            }
        }
        top = 0;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0) s[top++] = i;
        
        bool find = false;
        while (top > 0 && !find) {
            int u = s[--top];
           // cout << u << endl;
            for (int v = 0; v < n; ++v)
                if (g[u][v]) {
                    //cout << "tp " << v << endl;
                    if ((r[u] & r[v]).any()) find = true;
                    r[v] |= r[u]; 
                    if (--cnt[v] == 0) s[top++] = v;
                }
        }
        printf("Case #%d: ", cs);
        printf(find ? "Yes\n" : "No\n");
    }
    //system("pause");
    return 0;
}
/*
1
3
2 2 3
1 3
0

*/
