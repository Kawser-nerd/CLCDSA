
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

struct FAU {
    VI p, r;

    FAU(int n): p(n,-1), r(n,0) {}

    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    void join(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return ;

        if (r[x] > r[y]) p[y] = x;
        else p[x] = y;

        if (r[x] == r[y]) ++r[y];
    }
};

struct SAT2 {
    int n;
    VVI G; VI t;

    VB value; // OUT

    SAT2(int n): n(2 * n), G(2 * n), t(2 * n,-1), value(n) {}

    void sccV1(int v, VVI &G, VI &V, VB &vis) {
        vis[v] = 1;

        for (int u : G[v]) if (!vis[u]) {
            sccV1(u, G, V, vis);
        }

        V.pb(v);
    }

    void sccV2(int v, int nr, VVI &G, VB &vis) {
        vis[v] = 1;

        t[v] = nr;
        for (int u : G[v]) if (!vis[u]) {
            sccV2(u, nr, G, vis);
        }
    }

    int scc() {
        int nr = -1;

        VI V;
        VB vis(n,0);

        VVI Gt(n);
        FORE(i,G) FORE(j,G[i]) {
            Gt[G[i][j]].pb(i);
        }

        FORE(i,G) if (!vis[i]) {
            sccV1(i, Gt, V, vis);
        }

        FORE(i,vis) vis[i] = 0;

        FORDE(i,V) if (!vis[V[i]]) {
            nr++;
            sccV2(V[i], nr, G, vis);
        }

        return nr + 1;
    }

    void addConstraint(int a, bool neg_a, int b, bool neg_b) {
        G[2 * a + neg_a].pb(2 * b + 1 - neg_b);
        G[2 * b + neg_b].pb(2 * a + 1 - neg_a);
    }
    
    void mustBeTrue(int a) {
        addConstraint(a, false, a, false);
    }
    
    void mustBeFalse(int a) {
        addConstraint(a, true, a, true);
    }

    bool solveSat() {
        int cnt = scc();
        int v[cnt], c[cnt];

        FOR(i,0,n/2-1) if (t[2 * i] == t[2 * i + 1]) {
            return false;
        }

        FOR(i,0,n-1) v[ t[i] ] = i;
        FOR(i,0,cnt-1) c[i] = -1;

        FOR(i,0,cnt-1) if (c[i] == -1) {
            c[i] = 1;
            c[t[v[i] ^ 1]] = 0;
        }

        FOR(i,0,n/2-1) {
            value[i] = c[t[2 * i + 1]];
        }

        return true;
    }
};

/*************************************************************************/

int getOffset(int i, int j, int n, int m) {
    return 4 * (i * m + j);
}

bool solve(int n, int m, vector <string> &tab) {
    int vars = 0;
    FOR(i,0,n-1) FOR(j,0,m-1) vars += (tab[i][j] == '-' || tab[i][j] == '|');
    
    if (vars == 0) return false;

    int v = 4 * n * m;
    FAU fau(v);
    
    FOR(i,0,n-1) FOR(j,0,m-1) {
        int off = getOffset(i, j, n, m);
    
        FOR(d,0,1) {
            if (tab[i][j] == '.') {
                fau.join(off + d, off + d + 2);
            } else if (tab[i][j] == '/') {
                fau.join(off + 2 * d, off + 2 * d + 1);
            } else if (tab[i][j] == '\\') {
                fau.join(off + 2 * d + 1, off + (2 * d + 2) % 4);
            }
        }
    }
    
    FOR(i,0,n-1) FOR(j,0,m-1) FOR(d,0,1) {
        int ni = i, nj = j;
        if (d == 0) {
            nj--;
        } else {
            ni--;
        }
        
        if (ni < 0 || nj < 0) continue;
        
        int nd = d + 2;
        fau.join(getOffset(i, j, n, m) + d, getOffset(ni, nj, n, m) + nd);
    }
    
    VVP path(v);
    
    int varId = 0;
    FOR(i,0,n-1) FOR(j,0,m-1) if (tab[i][j] == '-' || tab[i][j] == '|') {
        int currVar = varId++;
        int off = getOffset(i, j, n, m);
        
        FOR(d,0,3) {
            int v = off + d;
            int neg = d % 2;
            
            path[fau.find(v)].pb({currVar, neg});
        }
    }
    
    SAT2 sat(vars);
    VP pathToShooter(v, {-1, -1});
    
    FOR(i,0,v-1) {
        auto vec = path[i];
    
        if (SIZE(vec) == 2) for (auto &e : vec) {
            if (e.nd == 0) {
                sat.mustBeTrue(e.st);
            } else {
                sat.mustBeFalse(e.st);
            }
        } else if (SIZE(vec) == 1) {
            pathToShooter[i] = vec[0];
        }
    }
    
    FOR(i,0,n-1) FOR(j,0,m-1) if (tab[i][j] == '.') {
        int off = getOffset(i, j, n, m);
        
        VI paths = {fau.find(off), fau.find(off + 1)};
        VP shooters;
        
        for (int v : paths) if (pathToShooter[v] != mp(-1,-1)) {
            shooters.pb(pathToShooter[v]);
        }
        
        if (shooters.empty()) {
            return false;
        } else if (SIZE(shooters) == 1) {
            shooters.pb(shooters[0]);
        }
        
        sat.addConstraint(shooters[0].st, !shooters[0].nd, shooters[1].st, !shooters[1].nd);
    }
    
    if (sat.solveSat()) {
        int varId = 0;
        FOR(i,0,n-1) FOR(j,0,m-1) if (tab[i][j] == '-' || tab[i][j] == '|') {
            int currVar = varId++;
            
            if (sat.value[currVar]) {
                tab[i][j] = '|';
            } else {
                tab[i][j] = '-';
            }
        }
    
        return true;
    } else {
        return false;
    }
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": ";
        
        int n, m;
        cin >> n >> m;
        
        vector <string> tab(n);
        FOR(j,0,n-1) {
            cin >> tab[j];
        }
        
        if (solve(n, m, tab)) {
            cout << "POSSIBLE\n";
            
            FOR(j,0,n-1) {
                cout << tab[j] << '\n';
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}

/*************************************************************************/

