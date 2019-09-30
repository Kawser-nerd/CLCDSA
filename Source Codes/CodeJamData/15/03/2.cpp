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
    cout << __PRETTY_FUNCTION__ << endl;
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

#define N 300010
int n,a[N];
const char *oijk="1ijk";
void input() {
    long l,x;
    static char s[N];
    scanf("%ld%ld%s",&l,&x,s);
    while ( x>30 ) x-=4;
    n=l*x;
    REP1(i,1,n) a[i]=strchr(oijk,s[(i-1)%l])-oijk+1;
}

const int m[5][5]={
    {0,0,0,0,0},
    {0,1,2,3,4},
    {0,2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};

int mul( int x, int y ) {
    int sx=x/abs(x);
    int sy=y/abs(y);
    return sx*sy*m[abs(x)][abs(y)];
}

int sl[N],sr[N];
bool _solve() {
    sl[0]=1;
    REP1(i,1,n) sl[i]=mul(sl[i-1],a[i]);
    sr[n+1]=1;
    for ( int i=n; i>=1; i-- ) sr[i]=mul(a[i],sr[i+1]);
    if ( sl[n]!=mul(2,mul(3,4)) ) return 0;
    int pi=1;
    while ( pi<=n && sl[pi]!=2 ) pi++;
    if ( pi>n ) return 0;
    int pk=n;
    while ( pk>=1 && sr[pk]!=4 ) pk--;
    if ( pk<=pi ) return 0;
    int si=1,sj=1,sk=1;
    REP1(i,1,n) {
        if ( i<=pi ) si=mul(si,a[i]);
        else if ( i<pk ) sj=mul(sj,a[i]);
        else sk=mul(sk,a[i]);
    }
    assert(si==2);
    assert(sj==3);
    assert(sk==4);
    return 1;
}
void solve() {
    puts(_solve()?"YES":"NO");
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

