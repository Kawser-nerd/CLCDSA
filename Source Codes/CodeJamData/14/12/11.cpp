

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }
    
#define pii pair<int, int>
int n;
const int INF = (int)12345;

vector<int> edg[INF];
bool vis[INF];

pii dfs(int i) {
    if (vis[i]) return pii(0, 0);
    vis[i] = 1;

    int nodes = 1;

    vector <int> sub;


    rep (g, (int)edg[i].size()) {
        int next = edg[i][g];
        if (vis[next]) continue;

        pii res = dfs(next);
        sub.push_back(res.second - res.first);
        nodes += res.second;
    }
    sort(all(sub));
    reverse(all(sub));
    if (sub.size() <= 1)
        return pii(nodes - 1, nodes);
    else
        return pii(nodes - sub[0] - sub[1] - 1, nodes);
}

    


void solve() {
    scanf("%d", &n);
    rep (i, n) edg[i].clear();
    rep (i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edg[a].pb(b);
        edg[b].pb(a);
    }
    int res = n;
    rep (i, n) {
        rep (j, n) vis[j] = 0;

        pii tmp = dfs(i);
        res = min(res, tmp.first);
        db(i);
        db(tmp.first);
    }
    printf("%d", res);
}

int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../B-small.in","r",stdin); freopen("../B-small.out","w",stdout);
    //  freopen("../B-small-attempt0.in","r",stdin);freopen("../B-small-attempt0.out","w",stdout);
    //  freopen("../B-small-attempt1.in","r",stdin);freopen("../B-small-attempt1.out","w",stdout);
    //  freopen("../B-small-attempt2.in","r",stdin);freopen("../B-small-attempt2.out","w",stdout);
    //  freopen("../B-large.in","r",stdin); freopen("../B-large.out","w",stdout)

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

