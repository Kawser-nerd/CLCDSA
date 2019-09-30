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

void WI( int x ) {
    printf("%d\n",x);
}

template<typename... Args>
void WI(int head, Args... tail) {
    printf("%d ",head);
    WI(tail...);
}
/// }}}

#define N 88
int n,c[N],ea[N],eb[N];
VI e[N];
void input() {
    RI(n);
    REP1(i,1,n) RI(c[i]);
    REP1(i,1,n-1) {
        ea[i]=i;
        RI(eb[i]);
    }
    REP1(i,1,n) e[i].clear();
    REP1(i,1,n-1) {
        e[ea[i]].PB(i);
        e[eb[i]].PB(i);
    }
}

bool vp[N],ve[N];

bool conn( int a, int b ) {
    static int que[N],ql,qr,vis[N],ucs;
    ql=qr=0; ucs++;
    vis[a]=ucs;
    que[qr++]=a;
    while ( ql!=qr && vis[b]!=ucs ) {
        int p=que[ql++];
        FOR(it,e[p]) if ( !ve[*it] ) {
            int to=p^ea[*it]^eb[*it];
            if ( vis[to]==ucs ) continue;
            vis[to]=ucs;
            que[qr++]=to;
        }
    }
    return vis[b]==ucs;
}

int dp[N];
int gao( int p, int f ) {
    int &ret=dp[p];
    if ( ret!=-1 ) return ret;
    ret=0;
    FOR(it,e[p]) if ( !ve[*it] ) {
        int to=p^ea[*it]^eb[*it];
        if ( to!=f ) ret=max(ret,gao(to,p));
    }
    if ( !vp[p] ) ret+=c[p];
    return ret;
}
int get_best( int p ) {
    memset(dp,-1,sizeof(dp));
    int ret=gao(p,0);
    return ret;
}

int go( int a, int b ) {
    if ( conn(a,b) ) {
        int ret=-1e9,base=0;
        if ( !vp[a] ) base+=c[a];
        vp[a]=1;
        bool flg=0;
        FOR(it,e[a]) if ( !ve[*it] ) {
            flg=1;
            int to=a^ea[*it]^eb[*it];
            ve[*it]=1;
            ret=max(ret,-go(b,to));
            ve[*it]=0;
        }
        if ( !flg ) {
            if ( a==b ) ret=0;
            else ret=max(ret,-go(b,a));
        }
        vp[a]=0;
        ret+=base;
        return ret;
    } else {
        int ca=get_best(a);
        int cb=get_best(b);
        return ca-cb;
    }
}

void solve() {
    int ans=-1e9;
    REP1(i,1,n) {
        int sml=1e9;
        REP1(j,1,n) {
            memset(vp,0,sizeof(vp));
            memset(ve,0,sizeof(ve));
            int now=go(i,j);
            //printf("%d,%d: %d\n",i,j,now);
            sml=min(sml,now);
        }
        ans=max(ans,sml);
    }
    printf("%d\n",ans);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    //fprintf(stderr,"n_case = %d\n",n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        if ( argc==3 && (i<atoi(argv[1]) || atoi(argv[2])<i) ) continue;
        if ( 1 || argc!=1 ) {
            fprintf(stderr,"Running #%d...\n",i);
            fflush(stderr);
        }
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

