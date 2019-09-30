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
#define packet 256
#define psize 400
#define tsize 100005

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
    int par;
    int size;
}node;

void resuf(node uft[]){
    int i;
    for(i=0;i<tsize;i++){
        uft[i].par=i;uft[i].size=1;
    }
    return;
}

int find(int x,node uft[]){
    if(uft[x].par==x){return x;}
    else{
      uft[x].par=find(uft[x].par,uft);
      return uft[x].par;
    }
}

void uni(int x,int y,node uft[]){
    int xp,yp;
    xp=find(x,uft);yp=find(y,uft);
    if(xp==yp){return;}
    if(uft[xp].size>uft[yp].size){
        uft[yp].par=xp;
        uft[xp].size+=uft[yp].size;
    }
    else{
        uft[xp].par=yp;
        uft[yp].size+=uft[xp].size;
    }
    return;
}

void tcpy(node a[],node b[]){
  int i;
  for(i=0;i<tsize;i++){
    a[i]=b[i];
  }
}

int sumsize(int a,int b,node uft[]){
  if(find(a,uft)==find(b,uft)){
    return uft[find(a,uft)].size;
  }
  return uft[find(a,uft)].size+uft[find(b,uft)].size;
}

int main(void){
    int i,j,n,m,k,c,h,w,r=0,l,t,q;
    int a[tsize],b[tsize];
    int qa[tsize],qb[tsize],qc[tsize];
    int st,fi,te;
    int res[tsize];
    int pakmem[packet];
    sd qmem[tsize];
    node uft[packet][tsize];
    node cache[tsize];
    scanf("%d%d",&n,&m);
    resuf(cache);
    for(i=0;i<m;i++){
      if(i%psize==0){
        tcpy(uft[i/psize],cache);
      }
      scanf("%d%d",&a[i],&b[i]);
      uni(a[i],b[i],cache);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      res[i]=-1;
      scanf("%d%d%d",&qa[i],&qb[i],&qc[i]);
      st=0;
      fi=(m-1)/psize;
      while(st<=fi){
        te=(st+fi)/2;
        w=sumsize(qa[i],qb[i],uft[te]);
        if(w<qc[i]){st=te+1;}else{fi=te-1;}
      }
      qmem[i].val=fi;
      qmem[i].node=i;
    }
    qsort(qmem,q,sizeof(qmem[0]),sdsortfnc);
    resuf(cache);
    for(i=0;i<m;i++){
      if(i%psize==0){
        st=inf;fi=-inf;
        for(j=0;j<q;j++){
          if(qmem[j].val==(i/psize)){
            st=min(st,j);
            fi=max(fi,j);
          }
        }
      }
      uni(a[i],b[i],cache);
      if(st==inf){continue;}
      for(j=st;j<=fi;j++){
        if(sumsize(qa[qmem[j].node],qb[qmem[j].node],cache)>=qc[qmem[j].node]){
          if(res[qmem[j].node]==-1){
            res[qmem[j].node]=i;
          }
        }
      }
    }
    for(i=0;i<q;i++){
      printf("%d\n",res[i]+1);
    }
    return 0;
} ./Main.c:19:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:20:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:26:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:33:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘shuffledget’:
./Main.c:69:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:168:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:174:7: warning: ...