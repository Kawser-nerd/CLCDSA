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
if(((sd*)a)->node < ((sd*)b)->node){return -1;}
if(((sd*)a)->node > ((sd*)b)->node){return 1;}
return 0;
}

long long sdsearch(sd x,sd a[],long long n){
    long long st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te].val<x.val){st=te+1;continue;}
        if(a[te].val>x.val){fi=te-1;continue;}
        if(a[te].node<x.node){st=te+1;continue;}
        if(a[te].node>x.node){fi=te-1;continue;}
        return te;
    }
    return -1;
}

//Dynamic Array

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

//Heap and Priority_queue

typedef struct{
long long node;
long long cost;
}data;

data heap[2097152];
long long hsize=0;

void resheap(){
    hsize=0;
    long long i;
    heap[0].node=-1;
    heap[0].cost=-llinf;
    for(i=1;i<2097152;i++){
        heap[i].node=-1;
        heap[i].cost=llinf;
    }
}

int swjud(data high,data low){
    if(high.cost > low.cost){return 1;}
    return -1;
}

void pqpush(data x){
    long long a,b;
    data m;
    hsize++;
    heap[hsize]=x;
    a=hsize;
    while(1){
        b=a/2;
        if(swjud(heap[b],heap[a]) == 1){
            m=heap[a];heap[a]=heap[b];heap[b]=m;
        }
        else{break;}
        a=b;
    }
}

data pqpop(){
    long long a,b,c;
    data m,sw;
    m=heap[1];
    heap[1]=heap[hsize];
    heap[hsize].node=-1;
    heap[hsize].cost=llinf;
    hsize--;
    a=1;
    while(1){
        b=a*2;c=a*2+1;
        if(swjud(heap[a],heap[b])==-1 && swjud(heap[a],heap[c])==-1){break;}
        if(swjud(heap[b],heap[c])==-1){
            sw=heap[a];heap[a]=heap[b];heap[b]=sw;
            a=b;
        }
        else{
            sw=heap[a];heap[a]=heap[c];heap[c]=sw;
            a=c;
        }
    }
    return m;
}

long long dijkstra(long long a,long long b,long long vc,rs g[],mkj x[]){
  resheap();
  long long i,j,dist[1048576],nv;
  for(i=0;i<=vc;i++){
    dist[i]=llinf;
  }
  data pd,od;
  pd.node=a;
  pd.cost=0;
  pqpush(pd);
  while(hsize>0){
    od=pqpop();
    nv=od.node;
    if(nv==b){return od.cost;}
    if(dist[nv]!=llinf){continue;}
    dist[nv]=od.cost;
    for(i=x[nv].st;i<x[nv].st+x[nv].kz;i++){
      if(dist[g[i].fi]!=llinf){continue;}
      pd.node=g[i].fi;
      pd.cost=od.cost+g[i].kr;
      pqpush(pd);
    }
  }
  return -1;
}


int main(void){
    long long i,j,n,m,k,h,w,r=0,l,t,cnt=0,p,q;
    long long a[524288],b[524288],c[524288];
    rs g[2097152];
    mkj x[524288];
    sd dat[524288],wa;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<m;i++){
      scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
      dat[2*i].val=a[i];
      dat[2*i].node=c[i];
      dat[2*i+1].val=b[i];
      dat[2*i+1].node=c[i];
    }
    qsort(dat,2*m,sizeof(dat[0]),sdsortfnc);
    w=0;
    dat[2*m].val=inf;
    for(i=0;i<2*m;i++){
      if(dat[i].val != dat[i+1].val || dat[i].node != dat[i+1].node){
        dat[w]=dat[i];
        w++;
      }
    }
    for(i=1;i<=n;i++){
      dat[w+i-1].val=i;
      dat[w+i-1].node=-1;
    }
    for(i=0;i<w;i++){
      g[cnt].st=i;
      g[cnt].fi=w+dat[i].val-1;
      g[cnt].kr=1;
      cnt++;
      g[cnt].fi=i;
      g[cnt].st=w+dat[i].val-1;
      g[cnt].kr=0;
      cnt++;
    }
    for(i=0;i<2*m;i++){
      wa.val=a[i];
      wa.node=c[i];
      p=sdsearch(wa,dat,w);
      wa.val=b[i];
      wa.node=c[i];
      q=sdsearch(wa,dat,w);
      g[cnt].st=p;
      g[cnt].fi=q;
      g[cnt].kr=0;
      cnt++;
      g[cnt].fi=p;
      g[cnt].st=q;
      g[cnt].kr=0;
      cnt++;
    }
    qsort(g,cnt,sizeof(g[0]),sortfnc);
    makemkj(g,x,cnt);
    printf("%lld\n",dijkstra(w,w+n-1,1048576,g,x));
    return 0;
} ./Main.c:16:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:17:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:23:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:30:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘shuffledget’:
./Main.c:66:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:251:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:253:7: warni...