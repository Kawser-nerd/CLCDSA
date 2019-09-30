#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define MAXS 1000010
using namespace std;

int read(){
    char c;
    while(((c=getchar())<'0' || c>'9') && c!='-');
    int flag=1;
    int res=c-'0';
    if(c=='-'){
        flag=-1;
        res=0;
    }
    while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
    return res*flag;
}

int n,m,v0,maxs;
int a[MAXN];
int lim[MAXN];
int f1[MAXS],f2[MAXS];
int p[20][MAXN][2];
int c[MAXN];

void calcP(int l){
    int last=1;
    for(int i=1;i<=n;i++){
        if(i==n || a[i+1]-a[i]>lim[l]){
            for(int j=last;j<=i;j++){
                p[l][j][0]=last;
                p[l][j][1]=i;
            }
            last=i+1;
        }
    }
    p[l][0][0]=1;
    p[l][n+1][1]=n;
}

void dp(){
    f1[0]=0; f2[0]=n+1;
    for(int s=1;s<maxs;s++){
        f2[s]=n+1;
        for(int i=1,l=1;i<=m;i++,l<<=1)
            if(s&l){
                f1[s]=max(f1[s],p[i][f1[s^l]+1][1]);
                f2[s]=min(f2[s],p[i][f2[s^l]-1][0]);
            }
    }
}

int main(){
#ifdef DEBUG
    freopen("g012e.in","r",stdin);
#endif
    n=read(); v0=read();
    for(int i=1;i<=n;i++) a[i]=read();
    lim[0]=v0;
    while(v0) lim[++m]=(v0/=2);
    maxs=1<<m;
    for(int i=0;i<=m;i++) calcP(i);
    dp();
    memset(c,-1,sizeof c);
    for(int i=0;i<maxs;i++)
        c[f2[i]]=max(c[f2[i]],f1[(maxs-1)^i]);
    int cur=-1,now=-1;
    for(int i=1;i<=n;i++)
        if(p[0][i][0]==i){
            while(cur<p[0][i][1]+1) now=max(now,c[++cur]);
            if(now>=i-1)
                for(int j=p[0][i][0];j<=p[0][i][1];j++)
                    puts("Possible");
            else
                for(int j=p[0][i][0];j<=p[0][i][1];j++)
                    puts("Impossible");
        }
    return 0;
}