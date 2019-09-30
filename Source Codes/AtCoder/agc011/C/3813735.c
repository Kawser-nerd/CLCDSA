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

long long n,m;
rs gr[524288];
mkj mk[524288];

long long color[524288]={0},flag;

long long rep(long long x,long long bc){
  if(color[x]!=0){
    if(color[x]==bc){flag=0;}
  }
  else{
    color[x]=3-bc;
    long long i;
    for(i=mk[x].st;i<mk[x].st+mk[x].kz;i++){
      rep(gr[i].fi,3-bc);
    }
  }
}

long long jud(long long x){
  if(mk[x].st==-1){return -1;}
  flag=1;
  rep(x,2);
  return flag;
}

long long main(void){
    long long i,j,sg=0,hs=0,nh=0,w;
    long long res;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<m;i++){
      scanf("%lld%lld",&gr[2*i].st,&gr[2*i].fi);
      gr[2*i+1].fi=gr[2*i].st;
      gr[2*i+1].st=gr[2*i].fi;      
    }
    for(i=1;i<=n;i++){
      mk[i].st=-1;
    }
    qsort(gr,2*m,sizeof(gr[0]),sortfnc);
    makemkj(gr,mk,2*m);
    for(i=1;i<=n;i++){
      if(color[i]!=0){continue;}
      w=jud(i);
      if(w==-1){sg++;}
      if(w==0){hs++;}
      if(w==1){nh++;}
    }
    res=(n*n)-((n-sg)*(n-sg));
    w=nh*nh*2;
    w+=(hs*nh*2);
    w+=(hs*hs);
    printf("%lld\n",res+w);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:74:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld",&gr[2*i].st,&gr[2*i].fi);
       ^