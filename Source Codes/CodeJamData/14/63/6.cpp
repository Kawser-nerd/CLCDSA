#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long Hash;

double curtime() {
    return double(clock()) / CLOCKS_PER_SEC;
}

const int maxn = 20010;
const int P = 237019;

bool uh[maxn];
Hash fh[maxn];
bool uo[maxn], fo[maxn];
int to[maxn], from[maxn];
int n;
vector<pii> g[maxn];
char c[maxn];

Hash hash(int e) {
    if (uh[e]) return fh[e];
    uh[e] = true;
    int i = from[e];
    int j = to[e];
    
    vector<Hash> vh;
    forn(q, g[j].size())
        if (g[j][q].first != i)
            vh.pb(hash(g[j][q].second));
    sort(vh.begin(), vh.end());

    Hash& res = fh[e];
    res = c[j];
    forn(i, vh.size()) res = res * P + vh[i];

    //printf("Hash(%d -> %d) is %lld\n", i + 1, j + 1, res);
    return res;
}

bool okline(int e) {
    // printf("call okline %d (%d -> %d)\n", e, from[e], to[e]);
    if (uo[e]) return fo[e];
    uo[e] = true;
    bool& res = fo[e];
    res = false;

    int fi = from[e];
    int j = to[e];

    vector<pair<Hash, int> > vh;
    forn(q, g[j].size())
        if (g[j][q].first != fi)
            vh.pb(make_pair(hash(g[j][q].second), g[j][q].second));
    sort(vh.begin(), vh.end());

    int bad_cnt = 0;
    int bad_edge = -1;
    size_t i = 0;
    for (i = 0; i + 1 < vh.size(); i += 2) {
        if (vh[i].first == vh[i + 1].first) continue;
        bad_cnt++;
        bad_edge = vh[i].second;
        i -= 1;
    }

    if (i != vh.size())
        bad_cnt++, bad_edge = vh.back().second;

    if (bad_cnt == 0) res = true;
    else if (bad_cnt > 1) res = false;
         else res = okline(bad_edge);

    // printf("okline (%d -> %d) is %d\n", fi + 1, j + 1, res);
    return res;
}   

bool solve() {
    scanf("%d", &n);
    char buf[5];
    int x, y;
    forn(i, n) scanf("%s", buf), c[i] = buf[0], g[i].clear();
    int e = 0;
    forn(i, n - 1) {
        scanf("%d %d", &x, &y);
        //printf("Add %d %d (%d)\n", x, y, e);
        x--, y--;
        g[x].pb(pii(y, e));
        g[y].pb(pii(x, e + 1));
        from[e] = x;
        to[e] = y;
        from[e + 1] = y;
        to[e + 1] = x;
        uo[e] = uo[e+1] = uh[e] = uh[e+1] = false;
        e += 2;
    }

    forn(i, e)
        if (hash(i) == hash(i ^ 1)) return true;

    forn(j, n) {
        vector<pair<Hash, int> > vh;
        forn(q, g[j].size())
            vh.pb(make_pair(hash(g[j][q].second), g[j][q].second));
        sort(vh.begin(), vh.end());
/*
        printf("Hashes for %d:\n", j + 1);
        forn(q, vh.size()) printf("%lld (to %d) ", vh[q].first, to[ vh[q].second ] + 1);
        printf("\n");
  */      
        vector<int> bade;
        size_t i = 0;
        for (i = 0; i + 1 < vh.size(); i += 2) {
            if (vh[i].first == vh[i + 1].first) continue;
            bade.pb(vh[i].second);
            i -= 1;
        }

        if (i != vh.size()) bade.pb(vh.back().second);

/*        printf(">");
        forn(q, bade.size()) printf(" %d", bade[q]);
        printf("\n");
  */      
        bool flag = bade.size() <= 2;
        forn(ii, bade.size())
            flag &= okline(bade[ii]);

        if (flag) return true;
    }
        
    return false;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        if (solve()) printf("SYMMETRIC\n");
        else printf("NOT SYMMETRIC\n");
        fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
    }
	return 0;
}
