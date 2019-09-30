//set many funcs template
//Ver.20181228
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384
#define vsize 524288
#define size 11111111

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int nHr(int a,int b){return nCr(a+b-1,b);}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}
int sankaku(int x){return ((1+x)*x)/2;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}
long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llsankaku(long long x){return ((1+x)*x)/2;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}
int chsortfncsj(const void *a,const void *b){if(*(char *)a>*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}
int chsortfnckj(const void *a,const void *b){if(*(char *)a<*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}

void shuffledget(int x[],int n){
    srand(time(0));
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={-1,-1,-1,0,0,1,1,1};
int dy8[8]={-1,0,1,-1,1,-1,0,1};

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}


typedef struct{
    int st;
    int fi;
}rs;

typedef struct{
    int st;
    int kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st == ((rs*)b)->st){return 0;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 1;
}

void makemkj(rs g[],mkj x[],int n){
    int i,ms=0,nst=g[0].st;
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

int mlis(int d,int sl[],int tl[]){
  int c=0,i,j,st,fi,te;
  for(i=0;i<=600;i++){
    if(i*i>d){break;}
    if(i*i+600*600<d){continue;}
    st=0;fi=600;
    while(st<=fi){
      te=(st+fi)/2;
      if(i*i+te*te==d){
        sl[c]=i;
        tl[c]=te;
        c++;
        break;
      }
      else if(i*i+te*te>d){fi=te-1;}
      else{st=te+1;}
    }
  }
  return c;
}

int n;
int vid(int a,int b){
  return 2*n*a+b;
}

//coloring bipartite graph
//color:1 or 2,nocolor = 0
void clbig(int ver,int pc,int col[],rs g[],mkj x[]){
  int i;
  if(col[ver]!=0){return;}
  col[ver]=3-pc;
  for(i=x[ver].st;i<x[ver].st+x[ver].kz;i++){
    clbig(g[i].fi,col[ver],col,g,x);
  }
}

int main(void){
    int i,j,m,k,a,b,c,h,w,r,l,t,ni,nj;
    int mem[4][4]={0};
    int as[1024],at[1024],ac;
    int bs[1024],bt[1024],bc;
    int acol[vsize]={0},bcol[vsize]={0};
    int ae=0,be=0;
    int agrt=0,bgrt=0;
    rs ga[size],gb[size];
    mkj ma[vsize],mb[vsize];
    scanf("%d%d%d",&n,&a,&b);
    ac=mlis(a,as,at);
    bc=mlis(b,bs,bt);
    for(i=0;i<2*n;i++){
      for(j=0;j<2*n;j++){
        for(k=0;k<ac;k++){
          ni=i+as[k];
          nj=j+at[k];
          if(!(ni>=2*n || nj>=2*n)){
            ga[ae].st=vid(i,j);
            ga[ae].fi=vid(ni,nj);
            ae++;
            ga[ae].fi=vid(i,j);
            ga[ae].st=vid(ni,nj);
            ae++;
          }

          if(as[k]==0 || at[k]==0){continue;}
          ni=i+as[k];
          nj=j-at[k];
          if(!(ni>=2*n || nj<0)){
            ga[ae].st=vid(i,j);
            ga[ae].fi=vid(ni,nj);
            ae++;
            ga[ae].fi=vid(i,j);
            ga[ae].st=vid(ni,nj);
            ae++;
          }
        }

        for(k=0;k<bc;k++){
          ni=i+bs[k];
          nj=j+bt[k];
          if(!(ni>=2*n || nj>=2*n)){
            gb[be].st=vid(i,j);
            gb[be].fi=vid(ni,nj);
            be++;
            gb[be].fi=vid(i,j);
            gb[be].st=vid(ni,nj);
            be++;
          }

          if(bs[k]==0 || bt[k]==0){continue;}
          ni=i+bs[k];
          nj=j-bt[k];
          if(!(ni>=2*n || nj<0)){
            gb[be].st=vid(i,j);
            gb[be].fi=vid(ni,nj);
            be++;
            gb[be].fi=vid(i,j);
            gb[be].st=vid(ni,nj);
            be++;
          }
        }
      }
    }
    for(i=0;i<vsize;i++){
      ma[i].st=0;
      ma[i].kz=0;
      mb[i].st=0;
      mb[i].kz=0;
    }
    qsort(ga,ae,sizeof(ga[0]),sortfnc);
    qsort(gb,be,sizeof(gb[0]),sortfnc);
    makemkj(ga,ma,ae);
    makemkj(gb,mb,be);
    for(i=0;i<4*n*n;i++){
      clbig(i,2,acol,ga,ma);
      clbig(i,2,bcol,gb,mb);
      mem[acol[i]][bcol[i]]++;
    }
    for(i=1;i<=2;i++){
      for(j=1;j<=2;j++){
        if(mem[i][j]>=n*n){
          agrt=i;
          bgrt=j;
        }
      }
    }
    r=0;
    for(i=0;i<2*n;i++){
      for(j=0;j<2*n;j++){
        if(acol[vid(i,j)]==agrt && bcol[vid(i,j)]==bgrt){
          if(r<n*n){
            printf("%d %d\n",i,j);
          }
          r++;
        }
      }
    }
    //printf("%d\n",r);
    return 0;
} ./Main.c:18:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:19:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:25:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:32:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘shuffledget’:
./Main.c:68:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:184:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^