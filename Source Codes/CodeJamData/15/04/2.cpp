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

#define M 25

struct P {
    int x,y;
};

bool operator <( const P &a, const P &b ) {
    return tie(a.x,a.y)<tie(b.x,b.y);
}

bool operator ==( const P &a, const P &b ) {
    return a.x==b.x && a.y==b.y;
}

void shift( vector<P> &ps ) {
    int lx=ps[0].x;
    int ly=ps[0].y;
    for (auto p : ps) {
        lx=min(lx,p.x);
        ly=min(ly,p.y);
    }
    for (auto &p : ps) {
        p.x-=lx;
        p.y-=ly;
    }
    sort(ALL(ps));
}

void rot( vector<P> &ps ) {
    for (auto &p : ps) p=P{p.y,-p.x};
}

vector<P> norm( vector<P> ps ) {
    shift(ps);
    vector<P> ret=ps;
    REP(i,4) {
        shift(ps);
        ret=min(ret,ps);
        rot(ps);
    }
    return ret;
}

struct Q {
    vector<P> ps;
    bool has( int x, int y ) {
        for (auto p : ps) if ( p.x==x && p.y==y ) return 1;
        return 0;
    }
};

bool operator <( const Q &a, const Q &b ) {
    return a.ps<b.ps;
}

bool operator ==( const Q &a, const Q &b ) {
    return a.ps==b.ps;
}

int n,r,c;
void input() {
    RI(n,r,c);
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
vector<Q> qs;
void build() {
    qs.clear();
    qs.push_back(Q{{P{0,0}}});
    while ( SZ(qs[0].ps)<n ) {
        vector<Q> nqs;
        for (auto &q : qs) {
            vector<P> nps;
            for (auto p : q.ps) REP(i,4) nps.PB(P{p.x+dx[i],p.y+dy[i]});
            sort(ALL(nps));
            nps.erase(unique(ALL(nps)),nps.end());
            for (auto p : nps) if ( !q.has(p.x,p.y) ) {
                q.ps.push_back(p);
                nqs.push_back(q);
                q.ps.pop_back();
            }
        }
        for (auto &q : nqs) q.ps=norm(q.ps);
        sort(ALL(nqs));
        nqs.erase(unique(ALL(nqs)),nqs.end());
        qs=nqs;
    }
    //printf("size = %d\n",SZ(qs));
}

bool out( int x, int y ) {
    return x<0 || x>=r || y<0 || y>=c;
}

bool mp[M][M];

int BFS( int ox, int oy ) {
    queue<int> que;
    auto push=[&]( int x, int y ) {
        mp[x][y]=1;
        que.push(x);
        que.push(y);
    };
    push(ox,oy);
    int cnt=0;
    while ( !que.empty() ) {
        int x=que.front(); que.pop();
        int y=que.front(); que.pop();
        cnt++;
        REP(i,4) {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if ( !out(xx,yy) && !mp[xx][yy] ) push(xx,yy);
        }
    }
    return cnt;
}

bool place( int ox, int oy, Q q ) {
    memset(mp,0,sizeof(mp));
    for (auto p : q.ps) {
        int xx=ox+p.x;
        int yy=oy+p.y;
        if ( out(xx,yy) ) return 0;
        mp[xx][yy]=1;
    }
    REP(i,r) REP(j,c) if ( !mp[i][j] ) {
        int cnt=BFS(i,j);
        if ( cnt%n!=0 ) return 0;
    }
    return 1;
}

bool test( Q q ) {
    // for (auto p : q.ps) printf("(%d,%d) ",p.x,p.y); puts("");
    REP(i,r) REP(j,c) REP(k,4) {
        shift(q.ps);
        if ( place(i,j,q) ) return 0;
        rot(q.ps);
    }
    return 1;
}

bool _solve() {
    if ( r>c ) swap(r,c);
    if ( n>c ) return 1;
    if ( n>=7 ) return 1;
    if ( r*c%n!=0 ) return 1;
    build();
    for (auto q : qs) if ( test(q) ) return 1;
    return 0;
}

void solve() {
    puts(_solve()?"RICHARD":"GABRIEL");
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

