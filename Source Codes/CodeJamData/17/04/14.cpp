#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

const int maxn=505;
int ai[maxn][maxn];
int bi[maxn][maxn];
int lai[maxn][maxn];
int lbi[maxn][maxn];
int G[maxn][maxn];
int banX[maxn],banY[maxn];
int vi[maxn],lk[maxn];

char opt[10];
int n,tot;

int Find(int x) {
    REP(i,1,tot) if(G[x][i] && !banY[i] && !vi[i]) {
        vi[i]=1;
        if(lk[i]==0 || Find(lk[i])) {
            lk[i]=x;return 1;
        }
    } return 0;
}

int kase;
void solve() {
    int m;
    read(n);read(m);
    memset(ai,0,sizeof(ai));
    memset(bi,0,sizeof(bi));
    REP(i,1,m) {
        scanf("%s",opt);
        int x,y;
        read(x);read(y);
        if(opt[0]=='+' || opt[0]=='o') ai[x][y]++;
        if(opt[0]=='x' || opt[0]=='o') bi[x][y]++;
    }
    REP(i,1,n) REP(j,1,n) lai[i][j]=ai[i][j],lbi[i][j]=bi[i][j];
    memset(banX,0,sizeof(banX));
    memset(banY,0,sizeof(banY));
    memset(G,0,sizeof(G));
    memset(lk,0,sizeof(lk));tot=n;
    REP(i,1,tot) REP(j,1,tot) if(bi[i][j]) banX[i]=banY[j]=1; else G[i][j]=1;
    REP(i,1,tot) if(!banX[i]) {
        memset(vi,0,sizeof(vi));Find(i);
    }
    REP(i,1,tot) if(!banY[i]) bi[lk[i]][i]++;
    memset(banX,0,sizeof(banX));
    memset(banY,0,sizeof(banY));
    memset(G,0,sizeof(G));
    memset(lk,0,sizeof(lk));tot=2*n-1;
    REP(i,1,tot) REP(j,1,tot) { // x + y - 1, x - y + n
        // i + j = 2x + n - 1
        if((i+j-n+1)%2==0) {
            int x=(i+j-n+1)/2,y=i-x+1;
            if(x>=1 && y>=1 && x<=n && y<=n) {
                if(ai[x][y]) banX[i]=banY[j]=1; else G[i][j]=1;
            }
        }
    }
    REP(i,1,tot) if(!banX[i]) {
        memset(vi,0,sizeof(vi));Find(i);
    }
    REP(i,1,tot) if(!banY[i] && lk[i]) {
        int p=lk[i],q=i;
        int x=(p+q-n+1)/2,y=p-x+1;ai[x][y]++;
    }
    int res=0;
    REP(i,1,n) REP(j,1,n) res+=ai[i][j]+bi[i][j];
    /*
    printf("=== A ===\n");
    REP(i,1,n) {
        REP(j,1,n) printf("%d ",ai[i][j]);putchar('\n');
    }
    printf("=== B ===\n");
    REP(i,1,n) {
        REP(j,1,n) printf("%d ",bi[i][j]);putchar('\n');
    }
    */
    int cnt=0;
    REP(i,1,n) REP(j,1,n) if(lai[i][j]!=ai[i][j] || lbi[i][j]!=bi[i][j]) ++cnt;
    printf("Case #%d: %d %d\n",++kase,res,cnt);
    REP(i,1,n) REP(j,1,n) if(lai[i][j]!=ai[i][j] || lbi[i][j]!=bi[i][j]) {
        if(ai[i][j] && bi[i][j]) printf("o %d %d\n",i,j);
        else if(ai[i][j]) printf("+ %d %d\n",i,j); else if(bi[i][j]) printf("x %d %d\n",i,j);
    }
}

int main() {
    int T;
    read(T);
    while(T--) solve();
    return 0;
}