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

vector<pair<string,map<LL,int> > > all;
LL pos[30000];
int n,m,k;
LL in[20];
char tmp[1000];
LL fac[20];
inline void readfile(){
    FILE* fin=fopen("data.txt","r");
    int c;
    fscanf(fin,"%d",&c);
    all.resize(c);
    REP(i,c){
        fscanf(fin,"%s",tmp);
        all[i].F=tmp;
        int cnt=0;
        int cc=fac[n];
        REP(j,n){
            if(j==0||tmp[j]==tmp[j-1])cnt++;
            else{
                //printf("(%d)\n",cnt);
                cc/=fac[cnt];
                cnt=0;
            }
        }
        cc/=fac[cnt];
        if(cc==0){
            puts(tmp);
            while(1);
        }
        pos[i]=cc;
        //printf("%s %I64d\n",tmp,pos[i]);
        //if(i>10)break;
        int d;
        fscanf(fin,"%d",&d);
        REP(j,d){
            int b;
            LL a;
            fscanf(fin,"%I64d%d",&a,&b);
            all[i].S[a]=b;
        }
    }
    fclose(fin);
}
int main(){
    CASET{
        fac[0]=1;
        REP1(i,1,19)fac[i]=fac[i-1]*i;
        DRI(r);
        RIII(n,m,k);
        readfile();
        printf("Case #%d:\n",cas++);
        REP(rr,r){
            if(rr%100==0)fprintf(stderr,"%d...\n",rr);
            REP(i,k)scanf("%I64d",&in[i]);
            int mp=-1;
            double ma=0;
            REP(i,SZ(all)){
                double c=1;
                REP(j,k){
                    map<LL,int>::iterator it=all[i].S.find(in[j]);
                    //if(all[i].F=="355555666688")printf("%d\n",it->S);
                    if(it==all[i].S.end()){
                        c=0;break;
                    }
                    c*=it->S;
                    //printf("c=%I64d\n",c);
                }
                //if(c>0)printf("%I64d %I64d\n",c,pos[i]);
                if(c*(double)pos[i]>ma){
                    ma=c*(double)pos[i];
                    mp=i;
                }
            }
            if(mp==-1){
                fprintf(stderr,"QQ rr=%d\n",rr);
                REP(i,k)fprintf(stderr,"%I64d ",in[i]);fprintf(stderr,"\n");
                puts(all[0].F.c_str());
            }else{
                //printf("mp=%d\n",mp);
                puts(all[mp].F.c_str());
            }
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

