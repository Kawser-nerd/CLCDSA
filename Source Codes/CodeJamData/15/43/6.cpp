
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

const int INF = 1e9;

#define MAXN 20000 //*2 jesli ograniczenia na wierzcholkach

struct MaxFlow { // indeksy: 1..n, dozwolone krawedzie wielokrotne i petle
    typedef VI::iterator iter;
    int n, d, dis[MAXN+1];
    VI v, c, G[MAXN+1];
    iter it[MAXN+1];

    void init(int n_) {
        n = n_;
        c.clear();
        v.clear();
        FOR(i,1,n) G[i].clear();
    }

    void add(int a, int b, int cc, bool bi = false) { // bidirectional?
        G[a].PB(SZ(v)); v.PB(b); c.PB(cc);
        G[b].PB(SZ(v)); v.PB(a); c.PB(cc * bi);
    }

    int aug(int x, int k) {
        if(x == d || !k) return k;
        for(iter& i = it[x]; i != G[x].end(); ++i)
            if(c[*i] > 0 && dis[v[*i]] == dis[x] + 1) {
                int f = aug(v[*i], min(k, c[*i]));
                if(f) {
                    c[*i] -= f; c[1^*i] += f;
                    return f;
                }
            }
        return 0;
    }

    LL flow(int s,int d_) {
        d = d_;
        LL res = 0;
        while(1) {
            FOR(i,1,n) dis[i] = -1, it[i] = G[i].begin();
            dis[s] = 0;
            queue<int> Q;
            Q.push(s);
            while(!Q.empty()) {
                int x = Q.front(); Q.pop();
                FORE(i,G[x]) if(c[*i] > 0 && dis[v[*i]] == -1) {
                    dis[v[*i]] = dis[x] + 1;
                    Q.push(v[*i]);
                }
            }
            if(dis[d] == -1) break;
            int f;
            while((f = aug(s,INF)))
                res += f;
        }
        return res;
    }
};

struct MaxFlow1Wrapper {
    MaxFlow f;
    void init(int n) {f.init(2*n);}
    void add(int a,int b,int c=1) {f.add(2*a, 2*b-1, c);}
    int flow(int s, int d) {
        FOR(i,1,f.n/2) f.add(2*i-1, 2*i,1);
        return f.flow(2*s, 2*d-1);
    }
};

MaxFlow1Wrapper F;

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    vector<vector<string> > cnt(n+2);
    map<string, int> M;
    string dummy;
    getline(cin, dummy);
    REP(i,n) {
        string S,s;
        getline(cin, S);
        stringstream ss(S);
        while(getline(ss, s, ' ')) {
            cnt[i].PB(s);
            M[s] = 0;
        }
    }
    int m = 0;
    FORE(it, M) it->Y = m++;
    F.init(m+2);
    FORE(it, cnt[0]) {
        F.add(1, M[*it]+3);
    }
    FORE(it, cnt[1]) {
        F.add(M[*it]+3, 2);
    }
    FOR(i, 2, n-1) {
        int k = SZ(cnt[i]);
        REP(a, k) REP(b, k) {
            if (a == b) continue;
            int s1 = M[cnt[i][a]], s2 = M[cnt[i][b]];
            F.add(s1+3, s2+3);
        }
    }
    int res = F.flow(1,2);
    cout << res << endl;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

