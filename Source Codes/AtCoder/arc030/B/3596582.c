//tree DP
//ABC036-D
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

long long dist[524288],par[524288];
void dfs(long long t,long long l,long long bp,rs g[],mkj x[]){
  long long i;
  if(dist[t]<=l){return;}
  dist[t]=l;
  par[t]=bp;
  for(i=x[t].st;i<x[t].st+x[t].kz;i++){
    dfs(g[i].fi,l+1,t,g,x);
  }
}

int main(void){
    long long i,j,n,m,k,a,b,c,h,w,r=0,l,t;
    long long bk,wk;
    long long res=0;
    long long dp[524288]={0};
    long long arr[524288];
    rs g[524288];
    mkj x[524288];
    sd dat[524288];
    scanf("%lld%lld",&n,&h);
    for(i=1;i<=n;i++){
      scanf("%lld",&arr[i]);
    }
    for(i=0;i<(n-1);i++){
      scanf("%lld%lld",&a,&b);
      g[2*i].st=a;
      g[2*i].fi=b;
      g[2*i].kr=1;
      g[2*i+1].st=b;
      g[2*i+1].fi=a;
      g[2*i+1].kr=1;
    }
    qsort(g,2*(n-1),sizeof(g[0]),sortfnc);
    makemkj(g,x,2*(n-1));
    for(i=0;i<=n;i++){
      dist[i]=inf;
    }
    dfs(h,0,-1,g,x);
    for(i=0;i<n;i++){
      dat[i].node=i+1;
      dat[i].val=dist[i+1];
    }
    qsort(dat,n,sizeof(dat[0]),sdsortfnc);
    for(i=0;i<n-1;i++){
      bk=0;
      w=dat[i].node;
      bk=dp[w];
      if(bk!=0 || arr[w]==1){
        bk+=2;
        dp[par[w]]+=bk;
      }
    }
    printf("%lld\n",dp[h]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&h);
     ^
./Main.c:80:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld",&arr[i]);
       ^
./Main.c:83:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld",&a,&b);
       ^