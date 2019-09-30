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

char tbl[]="ROYGBV";

string greedy( array<int,3> a ) {
    int n=a[0]+a[1]+a[2];
    assert(n>0);
    string s;
    int last=-1;
    REP(i,n) {
        int w=-1;
        REP(j,3) if ( j!=last && a[j] && (w==-1 || (i>0 && a[j]>a[w])) ) w=j;
        if ( w==-1 ) return "";
        s+=tbl[w*2];
        a[w]--;
        last=w;
    }
    assert(SZ(s)==n);
    if ( s[0]==s[n-1] ) return ""; 
    return s;
}

int n,c[6];
void input() {
    R(n);
    REP(i,6) R(c[i]);
}

string rep( string s, int k ) {
    string t;
    REP(i,k) t+=s;
    return t;
}

string check() {
    if ( c[1]+c[4]==n && c[1]==c[4] ) return rep("OB",n/2);
    if ( c[3]+c[0]==n && c[3]==c[0] ) return rep("GR",n/2);
    if ( c[5]+c[2]==n && c[5]==c[2] ) return rep("VY",n/2);
    if ( c[1] && c[1]>=c[4] ) return "";
    if ( c[3] && c[3]>=c[0] ) return "";
    if ( c[5] && c[5]>=c[2] ) return "";
    c[4]-=c[1];
    c[0]-=c[3];
    c[2]-=c[5];
    string s=greedy({{c[0],c[2],c[4]}});
    if ( s.empty() ) return s;
    string ans;
    for ( char i:s ) {
        ans.push_back(i);
        if ( i=='B' && c[1] ) { ans+=rep("OB",c[1]); c[1]=0; }
        if ( i=='R' && c[3] ) { ans+=rep("GR",c[3]); c[3]=0; }
        if ( i=='Y' && c[5] ) { ans+=rep("VY",c[5]); c[5]=0; }
    }
    return ans;
}

void solve() {
    int oc[6];
    memcpy(oc,c,sizeof(c));
    n=0;
    REP(i,6) n+=c[i];
    auto ans=check();
    if ( ans.empty() ) ans="IMPOSSIBLE";
    else {
        assert(SZ(ans)==n);
        REP(i,n) assert(ans[i]!=ans[(i+1)%n]);
        REP(i,n) {
            auto ptr=strchr(tbl,ans[i]);
            assert(ptr);
            int idx=ptr-tbl;
            oc[idx]--;
        }
        REP(i,6) assert(oc[i]==0);
    }
    W(ans);
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
