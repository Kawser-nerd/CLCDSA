//set many funcs template
//Ver.20180717
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

int minv[524288],maxv[524288];
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

int res[524288]={0};
int err=0;
bool fl[524288]={0};

void resdfs(int t,int bv,rs g[],mkj x[]){
  int i,nv;
  if(fl[t]==1){return;}
  fl[t]=1;
  if(minv[t]<=bv-1 && bv-1<=maxv[t]){
    nv=bv-1;
    res[t]=nv;
    for(i=x[t].st;i<x[t].st+x[t].kz;i++){
      resdfs(g[i].fi,nv,g,x);
    }    
  }
  else if(minv[t]<=bv+1 && bv+1<=maxv[t]){
    nv=bv+1;
    res[t]=nv;
    for(i=x[t].st;i<x[t].st+x[t].kz;i++){
      resdfs(g[i].fi,nv,g,x);
    }    
  }
  else{err=1;}
}

int main(void){
    int i,j,n,m,k,a,b,c,h,w,r=0,l,t;
    int v[524288],p[524288];
    rs g[524288];
    mkj x[524288];
    sd dat[524288];
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
      scanf("%d%d",&a,&b);
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
      minv[i]=-inf;
      maxv[i]=inf;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
      scanf("%d%d",&v[i],&p[i]);
      minv[v[i]]=p[i];
      maxv[v[i]]=p[i];
    }
    dfs(v[0],0,0,g,x);
    for(i=1;i<k;i++){
      if((p[0]+dist[v[i]])%2 != (p[i]%2)){
        printf("No\n");
        return 0;
      }
    }
    for(i=1;i<=n;i++){
      dat[i-1].node=i;
      dat[i-1].val=dist[i];
    }
    qsort(dat,n,sizeof(dat[0]),sdsortfnc);
    for(i=0;i<n;i++){
      w=dat[i].node;
      for(j=x[w].st;j<x[w].st+x[w].kz;j++){
        if(par[w]==g[j].fi){continue;}
        h=g[j].fi;
        minv[w]=max(minv[w],minv[h]-1);
        maxv[w]=min(maxv[w],maxv[h]+1);
      }
      if(minv[w]>maxv[w]){
        printf("No\n");
        return 0;
      }
    }
    resdfs(v[0],p[0]+1,g,x);
    if(err==1){
      printf("No\n");return 0;
    }
    printf("Yes\n");
    for(i=1;i<=n;i++){
      printf("%d\n",res[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:101:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:103:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&a,&b);
       ^
./Main.c:118:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&k);
     ^
./Main.c:120:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&v[i],&p[i]);
       ^