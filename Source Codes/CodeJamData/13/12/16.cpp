// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

int l[10100],r[10100];
int p[10100];
int val[10100];
int n;
LL e,rr;
inline bool cmp(int a,int b){
    return val[a]==val[b]?a>b:val[a]<val[b];
}
inline LL solve(int m,int x,int y,int ex,int ey){
        //printf("m=%d x=%d y=%d ex=%d ey=%d\n",m,x,y,ex,ey);
    if(m==-1){
        puts("QQ");
        printf("x=%d y=%d ex=%d ey=%d\n",x,y,ex,ey);
        return 0;
    }
    if(ey==ex+rr*(y-x))return 0;
    LL ans=0;
    LL c=ex+(m-x)*rr;
    if(c>=e)c=e;
    LL d=ey-(y-m)*rr;
    if(d<0)d=0;
    if(d>c){
        puts("QQ");
        printf("x=%d y=%d ex=%d ey=%d\n",x,y,ex,ey);
    }
    ans+=(c-d)*val[m];
    //printf("m=%d used %d\n",m,(int)(c-d));
    if(x<m){
        ans+=solve(l[m],x,m-1,ex,c-rr);
    }
    if(y>m){
        ans+=solve(r[m],m+1,y,d+rr,ey);
    }
    return ans;
}
int main(){
    CASET{
        scanf("%I64d%I64d%d",&e,&rr,&n);
        if(rr>e){rr=e;}
        REP(i,n){
            RI(val[i]);
        }
        set<int> XD;
        MS1(l);
        MS1(r);
        MS1(p);
        int root=0;
        REP1(i,1,n-1){
            int np=i-1;
            while(np!=root&&cmp(np,i))np=p[np];
            if(cmp(np,i)){
                l[i]=np;
                p[np]=i;
                root=i;
            }else{
                l[i]=r[np];
                if(r[np]!=-1)p[r[np]]=i;
                r[np]=i;
                p[i]=np;
            }
        }
        printf("Case #%d: %I64d\n",cas++,solve(root,0,n-1,e,0));
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

