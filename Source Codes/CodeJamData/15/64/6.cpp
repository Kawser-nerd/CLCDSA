
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}



#define MAXN (1000*2) //*2 jesli ograniczenia na wierzcholkach

struct MaxFlow1 { // indeksy: 1..n, dozwolone krawedzie wielokrotne
    int n, d;
    VI c, v, G[MAXN+1];
    bool vis[MAXN+1];

    void init(int n_) {
        n = n_;
        c.clear();
        v.clear();
        FOR(i,1,n) G[i].clear();
    }

    void add(int a,int b,int cc=1) {
        G[a].PB(SZ(v)); v.PB(b); c.PB(cc);
        G[b].PB(SZ(v)); v.PB(a); c.PB(0);
    }

    bool aug(int x) {
        if(x == d) return true;
        vis[x] = true;
        FORE(i,G[x])
            if(!vis[v[*i]] && c[*i] > 0 && aug(v[*i])) {
                c[*i]--; c[1^*i]++;
                return true;
            }
        return false;
    }

    int flow(int s,int d_) {
        d = d_;
        int res = 0;
        while(aug(s)) {
            memset(vis, 0, sizeof(vis)); // mozna zamienic na petle, jesli duzo malych flowow
            res++;
        }
        memset(vis, 0, sizeof(vis)); // mozna zamienic na petle, jesli duzo malych flowow
        return res;
    }

};

struct MaxFlow1Wrapper {
    MaxFlow1 f;
    void init(int n) {f.init(2*n);}
    void add(int a,int b,int c=1) {f.add(2*a, 2*b-1, c);}
    int flow(int s, int d) {
        FOR(i,1,f.n/2) f.add(2*i-1, 2*i);
        return f.flow(2*s, 2*d-1);
    }
};

MaxFlow1Wrapper M;

const int INF = 1e9;

struct vertex {
    int d[2];
    VI ng;

    vertex() {
        ng = VI();
        d[0]=d[1] = INF;
    }
};


void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n,m,k;
    cin >> n >> m >> k;
    M.init(n);
    vector<vertex> V(n);
    REP(i,m) {
        int a,b;
        cin >> a >> b;
        V[a].ng.PB(b);
        V[b].ng.PB(a);
    }
    int src = 0; 
    REP(t,2) {
        queue<int> Q;
        Q.push(src);
        V[src].d[t] = 0;
        while(!Q.empty()) {
            int f = Q.front();
            Q.pop();
            for (int g : V[f].ng) {
                if (V[g].d[t] == INF) {
                    V[g].d[t] = V[f].d[t]+1;
                    Q.push(g);
                }
            }
        }
        src = n-1;
    }
    int d = V[0].d[1];
    if (d == 1) {
        cout << 2 << endl;
        return;
    }
    REP(i,n) {
        for(int j : V[i].ng) {
            if (V[i].d[0]+1 == V[j].d[0] && V[i].d[1] == V[j].d[1]+1) {
                M.add(i+1,j+1);
     //           debug(MP(i,j));
            }
        }
    }
    int f = M.flow(1,n);
    cout << (V[0].d[1] + ((k>f)?2:1)) << endl;
   // debug(f);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);
    return 0;
}

