// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const long long &x ) { printf("%" PRId64,x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

struct SCC {
    int n;
    vector<vector<int>> e1, e2, scc;
    vector<int> grp, ord;
    void init(int _n) {
        n = _n;
        e1.clear();
        e1.resize(n);
        e2.clear();
        e2.resize(n);
    }
    void add(int a, int b) {
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    void dfs1(int u) {
        grp[u] = -1;
        for (int v : e1[u]) if (grp[v] == 0) dfs1(v);
        ord.push_back(u);
    }
    void dfs2(int u) {
        grp[u] = scc.size() - 1;
        scc.back().push_back(u);
        for (int v : e2[u]) if (grp[v] == -1) dfs2(v);
    }
    void solve() {
        grp.clear();
        grp.resize(n);
        ord.clear();
        ord.reserve(n);
        for (int i = 0; i < n; i++) if (grp[i] == 0) dfs1(i);
        reverse(ord.begin(), ord.end());
        scc.clear();
        grp.resize(n);
        for (int i : ord) if (grp[i] == -1) {
            scc.emplace_back();
            dfs2(i);
        }
    }
};

struct TwoSAT {
    int n;
    vector<bool> var;
    SCC scc;
    void init(int _n) {
        n = _n;
        scc.init(2 * n);
    }
    int inv(int x) {
        return x < n ? x + n : x - n;
    }
    void add(int a, int b) {
        scc.add(a, b);
        scc.add(inv(b), inv(a));
    }
    void add(int a, int x, int b, int y) {
        add(a + x * n, b + y * n);
    }
    bool solve() {
        scc.solve();
        var.clear();
        for (int i = 0; i < n; i++) if (scc.grp[i] == scc.grp[i + n]) return false;
        var.resize(n);
        for (int i = 0; i < n; i++) var[i] = (scc.grp[i + n] > scc.grp[i]);
        return true;
    }
} sat;

const int L=55;
const int N=110;

int h,w;
char s[L][L];
void input() {
    R(h,w);
    REP(i,h) R(s[i]);
}

bool blocked( int x, int y ) {
    return x<0 || x>=h || y<0 || y>=w || s[x][y]=='#';
}

// D R U L
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

VI pass[L][L];
void sim( int x, int y, int id, int d ) {
    while ( !blocked(x,y) ) {
        pass[x][y].PB(id);
        if ( s[x][y]=='|' || s[x][y]=='-' ) break;
        if ( s[x][y]=='/' ) {
            d^=3;
        } else if ( s[x][y]=='\\' ) {
            d^=1;
        }
        x+=dx[d];
        y+=dy[d];
    }
}

int bid[L][L];
bool ban[2*N];
void solve() {
    memset(bid,-1,sizeof(bid));
    memset(ban,0,sizeof(ban));
    int n=0;
    REP(i,h) REP(j,w) if ( s[i][j]=='|' || s[i][j]=='-' ) bid[i][j]=n++;
    REP(i,h) REP(j,w) pass[i][j].clear();
    REP(i,h) REP(j,w) if ( bid[i][j]!=-1 ) {
        int id=bid[i][j];
        sim(i+1,j,id+n,0);
        sim(i,j+1,id,1);
        sim(i-1,j,id+n,2);
        sim(i,j-1,id,3);
    }
    sat.init(n);
    REP(i,h) REP(j,w) if ( s[i][j]=='|' || s[i][j]=='-' )
        for ( int x:pass[i][j] ) ban[x]=1;
    REP(i,2*n) if ( ban[i] ) sat.add(i,sat.inv(i));
    REP(i,h) REP(j,w) if ( s[i][j]=='.' ) {
        VI v;
        for ( int x:pass[i][j] ) if ( !ban[x] ) v.PB(x);
        assert(SZ(v)<=2);
        if ( SZ(v)==0 ) {
            W("IMPOSSIBLE");
            return;
        } else if ( SZ(v)==1 ) {
            sat.add(sat.inv(v[0]),v[0]);
        } else if ( SZ(v)==2 ) {
            sat.add(sat.inv(v[0]),v[1]);
        }
    }
    bool ok=sat.solve();
    if ( !ok ) {
        W("IMPOSSIBLE");
    } else {
        W("POSSIBLE");
        REP(i,h) REP(j,w) if ( bid[i][j]!=-1 ) s[i][j]=(sat.var[bid[i][j]] ? '|' : '-');
        REP(i,h) W(s[i]);
    }
}

int main( int argc, char *argv[] ) {
    int n_case;
    R(n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
