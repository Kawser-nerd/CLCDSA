#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

set< set<pii> > su;
set<pii> start, need;
int n, m;
char s[64];
bool a[64][64];
pii q[64*64];
int qb, qf;
int ci[11], cj[11];

bool dfs(set<pii> ss) {
    // printf("ss.size() = %d\n", (int)ss.size());
    if (su.find(ss) != su.end()) return false;
    su.insert(ss);
    if (ss.size() == need.size() && ss == need) return true;

    for (int w = 1; w < 4; w++) {
        set<pii> nw;
        foreach(it, ss) {
            int ni = it->first;
            int nj = it->second;
            if (!a[ni+di[w]][nj+dj[w]]) ni += di[w], nj += dj[w];
            nw.insert(pii(ni, nj));
        }
        if (dfs(nw)) return true; 
    }
    
    return false;
}

void solve() {
    scanf("%d %d", &n, &m);
    int caves = 0;
    forn(i, n) {
        scanf("%s", s);
        forn(j, m) {
            a[i][j] = s[j] == '#';
            if (s[j] >= '0' && s[j] <= '9') {
                int id = s[j] - '0';
                caves = max(caves, id + 1);
                ci[id] = i;
                cj[id] = j;
            }
        }            
    }

    forn(qci, caves) {
        printf("%d: ", qci);
        start.clear();
        qb = qf = 0;
        q[qf++] = pii(ci[qci], cj[qci]);
        start.insert(pii(ci[qci], cj[qci]));

        need.clear();
        need.insert(pii(ci[qci], cj[qci]));

        while (qb < qf) {
            pii cur = q[qb++];
            forn(w, 3) {
                int ni = cur.first + di[w];
                int nj = cur.second + dj[w];
                if (a[ni][nj]) continue;
                if (start.find(pii(ni, nj)) != start.end()) continue;

                q[qf++] = pii(ni, nj);
                start.insert(pii(ni, nj));
            }
        }

        su.clear();

        printf("%d ", (int)start.size());

        if (dfs(start)) printf("Lucky\n");
        else printf("Unlucky\n");
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d:\n", q);
        solve();
    }
}
