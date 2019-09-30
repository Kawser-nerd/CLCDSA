//tree distfromroot and calcparent
//tenka12016-B
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val > ((sd*)b)->val){return -1;}
if(((sd*)a)->val < ((sd*)b)->val){return 1;}
return 0;
}

typedef struct{
    long long st;
    long long fi;
    long long kr;
}rs;

typedef struct{
    long long st;
    long long kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st == ((rs*)b)->st){return 0;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 1;
}

void makemkj(rs g[],mkj x[],long long n){
    long long i,ms=0,nst=g[0].st;
    for(i=1;i<n;i++){
        if(g[i].st!=g[i-1].st){
            x[nst].kz=i-ms;
            x[nst].st=ms;
            nst=g[i].st;ms=i;
        }
    }
    x[nst].kz=n-ms;
    x[nst].st=ms;
}

int dist[524288],par[524288];
void dfs(int t,int l,int bp,rs g[],mkj x[]){
  int i;
  if(dist[t]<=l){return;}
  dist[t]=l;
  par[t]=bp;
  for(i=x[t].st;i<x[t].st+x[t].kz;i++){
    dfs(g[i].fi,l+1,t,g,x);
  }
}

int main(void){
    int i,j,n,m,k,a,b,c,h,w,r=0,l,t;
    int res=0,num[524288];
    int v[524288],p[524288];
    rs g[524288];
    mkj x[524288];
    sd dat[524288];
    scanf("%d%d",&n,&k);
    scanf("%d",&t);
    if(t!=1){r++;}
    for(i=2;i<=n;i++){
      scanf("%d",&a);
      g[2*i-4].st=i;
      g[2*i-4].fi=a;
      g[2*i-4].kr=1;
      g[2*i-3].st=a;
      g[2*i-3].fi=i;
      g[2*i-3].kr=1;
    }
    qsort(g,2*(n-1),sizeof(g[0]),sortfnc);
    makemkj(g,x,2*(n-1));
    for(i=0;i<=n;i++){
      dist[i]=inf;
      num[i]=0;
    }
    dfs(1,0,0,g,x);
    for(i=1;i<=n;i++){
      dat[i-1].node=i;
      dat[i-1].val=dist[i];
    }
    qsort(dat,n,sizeof(dat[0]),sdsortfnc);
    for(i=0;i<n-1;i++){
      w=dat[i].node;
      h=0;
      for(j=x[w].st;j<x[w].st+x[w].kz;j++){
        if(par[w]==g[j].fi){continue;}
        h=max(h,num[g[j].fi]);
      }
      num[w]=h+1;
      if(dist[w]!=1 && num[w]==k){r++;num[w]=0;}
      //printf("%d %d %d %d\n",i,n-1,w,num[w]);
    }
    printf("%d\n",r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:77:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^
./Main.c:80:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^