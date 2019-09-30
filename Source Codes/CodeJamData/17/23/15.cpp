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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

void relax( LL &a, LL b, LL c ) {
    if ( b==-1 || c==-1 ) return;
    if ( a==-1 || b+c<a ) a=b+c;
}

const int N=110;
int n,q;
LL e[N],d[N][N];
double s[N];
void input() {
    R(n,q);
    REP1(i,1,n) R(e[i],s[i]);
    REP1(i,1,n) REP1(j,1,n) R(d[i][j]);
}

double dis[N];
bool vis[N];
const double INF=1e100;
void build( int st ) {
    REP1(i,1,n) dis[i]=INF;
    REP1(i,1,n) vis[i]=0;
    dis[st]=0;
    while ( 1 ) {
        int w=-1;
        REP1(i,1,n) if ( !vis[i] && (w==-1 || dis[i]<dis[w]) ) w=i;
        if ( w==-1 ) break;
        vis[w]=1;
        REP1(i,1,n) if ( !vis[i] && d[w][i]!=-1 && d[w][i]<=e[w] ) dis[i]=min(dis[i],dis[w]+d[w][i]/s[w]);
    }
}

void solve() {
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) relax(d[i][j],d[i][k],d[k][j]);
    vector<double> sol;
    REP(i,q) {
        int a,b;
        R(a,b);
        build(a);
        assert(dis[b]!=INF);
        sol.PB(dis[b]);
    }
    REP(i,q) printf("%.14f%c",sol[i],i+1==q?'\n':' ');
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
