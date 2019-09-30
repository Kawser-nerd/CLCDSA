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

#define N 20010

struct E {
    int a,b;
    void read() {
        RI(a,b);
    }
} e[N];

int n,m;
char clr[N];
VI es[N];
void input() {
    RI(n);
    REP1(i,1,n) scanf(" %c",clr+i);
    REP(i,n-1) e[i].read();
    REP(i,n-1) e[i+n-1]=E{e[i].b,e[i].a};
    m=2*(n-1);
    REP1(i,1,n) es[i].clear();
    REP(i,m) es[e[i].a].PB(i);
}

inline int inv( int eid ) { return eid<(n-1)?eid+(n-1):eid-(n-1); }

int dp_tid[N];
bool vis_tid[N];
map<pair<char,VI>,int> mp;

int get_tid( int eid ) {
    int &ret=dp_tid[eid];
    if ( vis_tid[eid] ) return ret;
    vis_tid[eid]=1;
    pair<char,VI> v;
    v.first=clr[e[eid].b];
    FOR(it,es[e[eid].b]) if ( *it!=inv(eid) ) {
        v.second.PB(get_tid(*it));
    }
    sort(ALL(v.second));
    if ( !mp.count(v) ) {
        int nmp=SZ(mp);
        mp[v]=nmp+1;
    }
    return ret=mp[v];
}

bool dp_chain[N],vis_chain[N];
bool find_chain( int eid ) {
    bool &ret=dp_chain[eid];
    if ( vis_chain[eid] ) return ret;
    vis_chain[eid]=1;
    vector<PII> v;
    FOR(it,es[e[eid].b]) if ( *it!=inv(eid) ) v.PB(MP(get_tid(*it),*it));
    sort(ALL(v));
    vector<PII> nv;
    REP(i,SZ(v)) {
        if ( i+1<SZ(v) && v[i].first==v[i+1].first ) i++;
        else nv.PB(v[i]);
    }
    if ( SZ(nv)>=2 ) return ret=0;
    if ( SZ(nv)==0 ) return ret=1;
    return ret=find_chain(nv[0].second);
}

void solve() {
    memset(vis_tid,0,sizeof(vis_tid));
    memset(vis_chain,0,sizeof(vis_chain));
    mp.clear();
    REP(i,n-1) if ( get_tid(i)==get_tid(inv(i)) ) {
        puts("SYMMETRIC");
        return;
    }
    REP1(i,1,n) {
        vector<PII> v;
        FOR(it,es[i]) v.PB(MP(get_tid(*it),*it));
        sort(ALL(v));
        vector<PII> nv;
        REP(i,SZ(v)) {
            if ( i+1<SZ(v) && v[i].first==v[i+1].first ) i++;
            else nv.PB(v[i]);
        }
        if ( SZ(nv)>=2 ) continue;
        if ( SZ(nv)==0 ) {
            puts("SYMMETRIC");
            return;
        }
        if ( SZ(nv)==1 && find_chain(nv[0].second) ) {
            puts("SYMMETRIC");
            return;
        }
    }
    puts("NOT SYMMETRIC");
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

