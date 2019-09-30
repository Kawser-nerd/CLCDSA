// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

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

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

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
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }

/// }}}

#define N 2010
int n,a[N][N];
void input() {
    char s[N];
    RI(n);
    n*=2;
    REP(i,n) {
        scanf("%s",s);
        REP(j,n) a[i][j]=s[j]-'0';
    }
}

void rotate() {
    static int ta[N][N];
    memcpy(ta,a,sizeof(a));
    REP(i,n) REP(j,n) a[i][j]=ta[j][n-i-1];
}

int b[N];
int solve_row() {
    REP(i,n) {
        bool f0=1,f1=1;
        REP(j,n) {
            if ( a[i][j]!=a[0][j] ) f0=0;
            if ( a[i][j]==a[0][j] ) f1=0;
        }
        if ( f0 ) b[i]=0;
        else if ( f1 ) b[i]=1;
        else return -1;
    }
    if ( count(b,b+n,0)!=count(b,b+n,1) ) return -1;
    int c1=0,c2=0;
    REP(i,n) {
        c1+=(b[i]!=i%2);
        c2+=(b[i]==i%2);
    }
    return min(c1,c2)/2;
}

void solve() {
    int a1=solve_row();
    rotate();
    int a2=solve_row();
    if ( a1==-1 || a2==-1 ) puts("IMPOSSIBLE");
    else printf("%d\n",a1+a2);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

