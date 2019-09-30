//set many funcs template
//Ver.20181228
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 998244353
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
return 0;
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

long long factorial[256];

void cfact(){
    long long i;
    factorial[0]=1;
    factorial[1]=1;
    for(i=2;i<256;i++){
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
    }
}

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

long long modular_inverse(long long n){
	return power(n, mod-2);
}

long long calcnCr(long long n,long long k){
	return (factorial[n]*(modular_inverse(factorial[k])*modular_inverse(factorial[n-k])%mod))%mod;
}

int main(void){
    cfact();
    long long i,j,k,n,r,v,w,c;
    point pts[256],o,vb;
    scanf("%lld",&n);
    r=power(2,n);
    r+=mod;
    r-=(n+1);
    r%=mod;
    for(i=0;i<n;i++){
      scanf("%lld%lld",&pts[i].xz,&pts[i].yz);
    }
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        o=pts[i];
        v=-1;
        w=-1;
        c=0;
        vb=vector_minus(pts[j],pts[i]);
        for(k=n-1;k>=0;k--){
          if(crossproduct(vector_minus(pts[k],o),vb)==0){
            c++;
            w=v;v=k;
          }
        }
        if(v!=i || w!=j){continue;}
        //printf("%lld %lld %lld\n",i,j,c);
        r+=mod;
        r-=power(2,c);
        r+=(c+1);
        r%=mod;
      }
    }
    printf("%lld\n",r);
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
./Main.c:170:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:176:7: warning: ign...