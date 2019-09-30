// {{{ by shik
#ifndef YCM
#pragma GCC optimize("O3")
#endif
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

const int INF=1e6; // care overflow of n * INF.

struct KM { // bipartite weighted maximum matching
    static const int N=110;
    int n,my[N],w[N][N],lx[N],ly[N],slk[N];
    bool vx[N],vy[N];
    void init( int _n ) {
        n=_n;
        REP(i,n) REP(j,n) w[i][j]=-INF;
    }
    int& operator()( int i, int j ) { return w[i][j]; }
    bool go( int p ) {
        vx[p]=1;
        REP(i,n) {
            int t=lx[p]+ly[i]-w[p][i];
            if ( t>0 ) {
                if ( t<slk[i] ) slk[i]=t;
                continue;
            }
            if ( vy[i] ) continue;
            vy[i]=1;
            if ( my[i]==-1 || go(my[i]) ) {
                my[i]=p;
                return 1;
            }
        }
        return 0;
    }
    int solve() {
        REP(i,n) lx[i]=-INF;
        memset(ly,0,n*sizeof(int));
        memset(my,-1,n*sizeof(int));
        REP(i,n) REP(j,n) if ( w[i][j]>lx[i] ) lx[i]=w[i][j];
        REP(i,n) {
            REP(j,n) slk[j]=INF;
            while ( 1 ) {
                memset(vx,0,n*sizeof(bool));
                memset(vy,0,n*sizeof(bool));
                if ( go(i) ) break;
                int sml=INF;
                REP(j,n) if ( !vy[j] && slk[j]<sml ) sml=slk[j];
                REP(j,n) {
                    if ( vx[j] ) lx[j]-=sml;
                    if ( vy[j] ) ly[j]+=sml;
                    else slk[j]-=sml;
                }
            }
        }
        REP(i,n) if ( w[my[i]][i]==-INF ) return -INF;
        int ans=0;
        REP(i,n) ans+=w[my[i]][i];
        return ans;
    }
} km;

const int N=110;
const int L=110;

template<typename T>
struct Queue {
    T dat[2*L*L];
    int fr,bk;
    void clear() { fr=bk=0; }
    bool empty() { return fr==bk; }
    void push( const T &x ) { dat[bk++]=x; }
    void pop() { fr++; }
    T front() { return dat[fr]; }
};
Queue<int> q;

int h,w,m;
char s[L][L];
void input() {
    R(w,h,m);
    REP(i,h) R(s[i]);
}

bool out( int x, int y ) {
    return x<0 || x>=h || y<0 || y>=w;
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int dis[L][L],mark[L][L];
void BFS( int sx, int sy ) {
    REP(i,h) REP(j,w) dis[i][j]=INF;
    q.clear();
    auto push=[&]( int x, int y, int d ) {
        if ( dis[x][y]!=INF || mark[x][y]==2 ) return;
        dis[x][y]=d;
        if ( mark[x][y]==1 ) return;
        q.push(x);
        q.push(y);
    };
    push(sx,sy,0);
    while ( !q.empty() ) {
        int x=q.front(); q.pop();
        int y=q.front(); q.pop();
        int nd=dis[x][y]+1;
        REP(i,4) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ( out(nx,ny) || s[nx][ny]=='#' ) continue;
            push(nx,ny,nd);
        }
    }
    REP(i,h) REP(j,w) mark[i][j]=0;
}

template<typename F>
void cross( int tx, int ty, F f ) {
    for ( int x=tx; x>=0 && s[x][ty]!='#'; x-- ) f(x,ty);
    for ( int x=tx; x<h  && s[x][ty]!='#'; x++ ) f(x,ty);
    for ( int y=ty; y>=0 && s[tx][y]!='#'; y-- ) f(tx,y);
    for ( int y=ty; y<w  && s[tx][y]!='#'; y++ ) f(tx,y);
}

int min_dis( int tx, int ty ) {
    int md=dis[tx][ty];
    cross(tx,ty,[&]( int x, int y ) { chkmin(md,dis[x][y]); });
    return md;
}

void parse( int &n, int x[], int y[], int id[L][L], char ch ) {
    n=0;
    REP(i,h) REP(j,w) if ( s[i][j]==ch ) {
        x[n]=i;
        y[n]=j;
        id[i][j]=n++;
    }
}

bool check( int sx, int sy, int tx, int ty, int d ) {
    REP(i,h) REP(j,w) if ( s[i][j]=='T' ) cross(i,j,[&]( int x, int y ) { mark[x][y]=1; });
    REP(i,h) REP(j,w) if ( s[i][j]=='T' ) mark[i][j]=2;
    // dump(sx,sy,tx,ty,d);
    // REP(i,h) REP(j,w) if ( mark[i][j] ) dump(i,j,mark[i][j]);
    BFS(sx,sy);
    int md=min_dis(tx,ty);
    // assert(md==INF || md==d); XXX
    return md==d;
}

int ns,nt,sx[N],sy[N],sid[L][L],tx[N],ty[N],tid[L][L],mat[N];
void solve() {
    parse(ns,sx,sy,sid,'S');
    parse(nt,tx,ty,tid,'T');
    int n=max(ns,nt);
    km.init(n); // sadly, it's max matching...
    REP(i,ns) {
        BFS(sx[i],sy[i]);
        REP(j,nt) {
            int d=min_dis(tx[j],ty[j]);
            if ( d>m ) continue;
            km(i,j)=-d;
        }
    }
    km.solve();
    REP(i,n) mat[km.my[i]]=i;
    vector<PII> vm;
    REP(i,ns) if ( mat[i]<nt && km.w[i][mat[i]]!=-INF ) vm.PB({i,mat[i]});
    // dump(vm);
    vector<PII> sol;
    while ( !vm.empty() ) {
        bool found=0;
        REP(i,SZ(vm)) {
            int si=vm[i].first,ti=vm[i].second;
            bool ok=check(sx[si],sy[si],tx[ti],ty[ti],-km.w[si][ti]);
            // dump(i,vm[i],ok);
            if ( ok ) {
                sol.PB(vm[i]);
                s[tx[ti]][ty[ti]]='t';
                swap(vm[i],vm.back());
                vm.pop_back();
                i--;
                found=1;
            }
        }
        assert(found);
    }
    W(SZ(sol));
    for ( auto i:sol ) W(i.first+1,i.second+1);
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
