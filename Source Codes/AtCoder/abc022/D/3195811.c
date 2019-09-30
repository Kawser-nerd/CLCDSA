//set many funcs template
//Ver.20180717
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
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

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

long long array[131072];
long long pt=0;

void push(long long x){
  array[pt]=x;
  pt++;
}

long long pop(){
  pt--;
  long long r=array[pt];
  return r;
}

typedef struct{
  long long xz;
  long long yz;
}point;

point vector_plus(point a,point b){
  point r;
  r.xz=a.xz+b.xz;
  r.yz=a.yz+b.yz;
  return r;
}

point vector_minus(point a,point b){
  point r;
  r.xz=a.xz-b.xz;
  r.yz=a.yz-b.yz;
  return r;
}

//naiseki
long long dotproduct(point a,point b){
  return a.xz*b.xz+a.yz*b.yz;
}

//gaiseki
long long crossproduct(point a,point b){
  return a.xz*b.yz-a.yz*b.xz;
}

long long basedist(point a,point b){
  double x,y;
  x=b.xz-a.xz;
  y=b.yz-a.yz;
  return x*x+y*y;
}

double dist(point a,point b){
  double x,y;
  x=b.xz-a.xz;
  y=b.yz-a.yz;
  return sqrt(x*x+y*y);
}

point base;

int degsortfnc(const void *a,const void *b){
  long long t;
  double p,q;
  point va,vb;
  va.xz=(((point*)a)->xz);
  va.yz=(((point*)a)->yz);
  vb.xz=(((point*)b)->xz);
  vb.yz=(((point*)b)->yz);  
  t=crossproduct(vector_minus(va,base),vector_minus(vb,base));
  if(t>0){return -1;}
  if(t<0){return 1;}
  p=basedist((va),base);
  q=basedist((vb),base);
  if(p>q){return -1;}
  if(p<q){return 1;}
  return 0;
}

long long debug(point x[],long long pts){
  long long i;
  for(i=0;i<pts;i++){
    printf("%lld %lld\n",x[i].xz,x[i].yz);
  }
  printf("\n");
}

long long convexhull(point x[],long long pts,point r[]){
  pt=0;
  point k[131072],l[131072];
  long long i,p=0,c,fir,sec;
  for(i=1;i<pts;i++){
    if(x[i].yz<x[p].yz){p=i;}
    if(x[i].yz==x[p].yz && x[i].xz<x[p].xz){p=i;}
  }
  base=x[p];
  c=0;
  for(i=0;i<pts;i++){
    if(i==p){continue;}
    k[c]=x[i];
    c++;
  }
  qsort(k,pts-1,sizeof(k[0]),degsortfnc);
  l[0]=base;
  l[1]=k[0];
  c=2;
  for(i=1;i<pts-1;i++){
    if(crossproduct(vector_minus(k[i-1],base),vector_minus(k[i],base))==0){continue;}
    l[c]=k[i];
    c++;
  }
  push(0);
  push(1);
  push(2);
  for(i=3;i<c;i++){
    fir=pop();
    sec=pop();
    while(crossproduct(vector_minus(l[i],l[sec]),vector_minus(l[fir],l[sec]))>=0){
      fir=sec;
      sec=pop();
    }
    push(sec);
    push(fir);
    push(i);
  }
  for(i=0;i<pt;i++){
    if(c<=array[i]){return i;}
    r[i]=l[array[i]];
  }
  return pt;
}

int main(void){
    long long i,j,n,m,k,c,h,w,r=0,l,t;
    point a[131072],b[131072];
    point ac[131072],bc[131072];
    double da,db;
    char s[524288];
    scanf("%lld",&n);
    for(i=0;i<n;i++){
      scanf("%lld%lld",&a[i].xz,&a[i].yz);
    }
    for(i=0;i<n;i++){
      scanf("%lld%lld",&b[i].xz,&b[i].yz);
    }
    h=convexhull(a,n,ac);
    //debug(ac,h);
    da=dist(ac[0],ac[h-1]);
    for(i=0;i<h-1;i++){
      da+=dist(ac[i],ac[i+1]);
    }
    h=convexhull(b,n,bc);
    //debug(bc,h);
    db=dist(bc[0],bc[h-1]);
    for(i=0;i<h-1;i++){
      db+=dist(bc[i],bc[i+1]);
    }
    printf("%.12lf\n",db/da);
    return 0;
} ./Main.c: In function ‘shuffledget’:
./Main.c:50:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:215:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:217:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld",&a[i].xz,&a[i].yz);
       ^
./Main.c:220:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld",&b[i].xz,&b[i].yz);
       ^