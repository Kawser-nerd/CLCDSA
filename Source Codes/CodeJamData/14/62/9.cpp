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

const int N=(1<<12)+10;

bool reduce( int n, int a[], int b[] ) {
    for ( int i=0; i<n; i+=2 ) {
        if ( a[i]+1!=a[i+1] ) return 0;
        b[i/2]=a[i]/2;
    }
    return 1;
}

long go( int n, int a[], int c ) {
    //dump(n,VI(a,a+n),c);
    if ( n==1 ) {
        long ret=1;
        REP1(i,1,c) ret*=i;
        return ret;
    }
    int b[N];
    long ret=0;
    int p1=-1,p2=-1,p3=-1;
    for ( int i=0; i<n; i+=2 ) if ( a[i]+1!=a[i+1] ) {
        if ( p1==-1 ) p1=i;
        else if ( p2==-1 ) p2=i;
        else p3=i;
    }
    if ( p1==-1 ) {
        if ( reduce(n,a,b) ) ret+=go(n/2,b,c);
    } else if ( p2==-1 ) {
        swap(a[p1],a[p1+1]);
        if ( reduce(n,a,b) ) ret+=go(n/2,b,c+1);
    } else if ( p3==-1 ) {
        REP(i,2) REP(j,2) {
            swap(a[p1+i],a[p2+j]);
            if ( reduce(n,a,b) ) ret+=go(n/2,b,c+1);
            swap(a[p1+i],a[p2+j]);
        }
    }
    return ret;
}

int n,a[N];
void input() {
    RI(n);
    n=1<<n;
    REP(i,n) RI(a[i]);
}

void solve() {
    REP(i,n) a[i]--;
    long ans=go(n,a,0);
    printf("%ld\n",ans);
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

