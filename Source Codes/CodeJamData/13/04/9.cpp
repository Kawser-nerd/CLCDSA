#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ws ws_fdhsdsj
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int k, n;
int type[1000];
vi loot[1000];
int ans[1000];
int num[1000];
int was[1000];
int cc[1000];
int num1[1000];
int was1[1000];
int ws[1000];
vi G[1000];



bool fans;
const int MX = 1 + 200 + 200 + 5;
void init() {
    for (int i = 0; i < MX; i++) {
        ws[i] = false;
        G[i].clear();
    }
}
void add(int x, int y) {
    G[x].pb(y);
}
bool ch;
void open(int i) {
    //cerr<<"Open "<<i + 1<<endl;
    cc[type[i]]--;            
    num1[type[i]]--;
    ch = true;
    was1[i] = 1;
    for (int j = 0; j < sz(loot[i]); j++) {
        num1[loot[i][j]]++;
    }
    //cerr<<"Rest 3 = "<<num1[3]<<endl;
}
int last = -1;
bool dfs(int v, int en) {
    if (v == en) {
        return true;
    }
    ws[v] = true;
    for (int i = 0; i < sz(G[v]); i++) {
        if (!ws[G[v][i]]) {
            if (dfs(G[v][i], en)) {
                if (v >= 1 && v < 1 + n) {
                    //open(v - 1);
                    last = v - 1;
                }
                return true;
            }
        }
    }
    return false;
}
bool can() {
    for (int i = 0; i < n; i++) {
        was1[i] = was[i];
        if (was[i] == 0) {
        }
    }
    for (int i = 0; i <= 200; i++) {
        num1[i] = num[i];
        if (num[i] > 0) {
        }
        cc[i] = 0;
    }
    for (int i = 0; i < n; i++) if (was1[i] == 0) {
        cc[type[i]]++;            
    }
    while (1) {
        ch = false;
        for (int i = 0; i < n; i++) if (was1[i] == 0 && cc[type[i]] <= num1[type[i]]) {
            open(i);
        }
        if (ch) continue;
        for (int cl = 0; cl <= 200; cl++) if (num1[cl] > 0 && cc[cl] > 0) {
            init();
            for (int i = 0; i < n; i++) if (was1[i] == 0 && type[i] == cl) {
                add(0, i + 1);
            }
            for (int i = 0; i < n; i++) if (was1[i] == 0) {
                for (int j = 0; j < sz(loot[i]); j++) {
                    add(i + 1, n + 1 + loot[i][j]);
                }
                add(n + 1 + type[i], 1 + i);
            }
            if (dfs(0, n + 1 + cl)) {
                assert(last != -1);
                open(last);
            }
        }
        if (!ch) break;
    }
    for (int i = 0; i < n; i++) {
        if (was1[i] == 0) {
            return false;
        }
    }
    return true;
}
void bct(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
        fans = true;
        return;
    }
    if (!can()) return;
    for (int i = 0; i < n; i++) if (was[i] == 0 && num[type[i]] > 0) {
        num[type[i]]--;
        was[i] = 1;
        ans[cur] = i + 1;      
        for (int j = 0; j < sz(loot[i]); j++) {
            num[loot[i][j]]++;
        }
        bct(cur + 1);
        if (fans) return;
        num[type[i]]++;
        was[i] = 0;
        ans[cur] = 0;      
        for (int j = 0; j < sz(loot[i]); j++) {
            num[loot[i][j]]--;
        }
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK"2.out", "w", stdout));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ti++) {
        cerr<<"Test "<<ti<<endl;
        printf("Case #%d: ", ti + 1);
        scanf("%d %d", &k, &n);
        for (int i = 0; i <= 200; i++) {
            num[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);            
            num[x]++;
        }
        for (int i = 0; i < n; i++) {
            int k0;
            scanf("%d %d", &type[i], &k0);
            loot[i].clear();
            for (int j = 0; j < k0; j++) {
                int x;
                scanf("%d", &x);
                loot[i].pb(x);
            }
        }
        for (int i = 0; i < n; i++) {
            was[i] = 0;
        }
        fans = false;
        bct(0);
        if (!fans) {
            printf("IMPOSSIBLE\n");
        }
    }
    #ifdef home                    
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 