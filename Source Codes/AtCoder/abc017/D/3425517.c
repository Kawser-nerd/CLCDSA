//lazy Segtree
//Codefestival2018 qual A-D
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

long long search(long long x,long long a[],long long n){
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
if(((sd*)a)->node < ((sd*)b)->node){return -1;}
if(((sd*)a)->node > ((sd*)b)->node){return 1;}
return 0;
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

long long inv2;

long long ssize=524288;
long long stree[1048576],lazy[1048576],vd=0;

void sinit(){
    inv2=modular_inverse(2);
    long long i,j;
    for(i=0;i<2*ssize;i++){
        stree[i]=0;
        lazy[i]=0;
    }
    return;
}

//lazy evaluation
void eval(long long k){
  if(lazy[k]!=0){
    stree[k]+=lazy[k];
    stree[k]%=mod;
    if(k<(ssize-1)){
      lazy[2*k+1]+=((lazy[k])*inv2);
      lazy[2*k+1]%=mod;
      lazy[2*k+2]+=((lazy[k])*inv2);
      lazy[2*k+2]%=mod;
    }
    lazy[k]=0;
  }
  return;
}

void upd(long long k,long long a){
    long long i,m,w,l,r;
    long long mem[128];
    long long ld,rd,md;
    k+=ssize-1;
    mem[0]=k;
    w=1;
    while(k>0){
        k=(k-1)/2;
        mem[w]=k;
        w++;
    }
    l=0;r=ssize;
    eval(0);
    for(i=w-1;i>0;i--){
      eval((2*mem[i])+1);
      eval((2*mem[i])+2);
    }
    stree[mem[0]]=a;
    lazy[mem[0]]=0;
    for(i=1;i<w;i++){
        k=mem[i];
        ld=stree[2*k+1];
        rd=stree[2*k+2];
        md=ld+rd;
        md%=mod;
        stree[k]=md;
    }
    return;
}

//add +t [a,b)
//call:k=0,l=0,r=ssize
void addquery(long long a,long long b,long long t,long long k,long long l,long long r){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k);
    if(r<=a || b<=l){return;}
    if(a<=l && r<=b){
        lazy[k]+=(t*(r-l));
        lazy[k]%=mod;
        eval(k);
        return;
    }
    else{
        eval(k*2+1);
        eval(k*2+2);
        addquery(a,b,t,k*2+1,l,(l+r)/2);
        addquery(a,b,t,k*2+2,(l+r)/2,r);
        stree[k]=(stree[k*2+1]+stree[k*2+2])%mod;
        lazy[k]=0;
        return;
    }
}

//calc sum[a,b)
//call:k=0,l=0,r=ssize
long long sumquery(long long a,long long b,long long k,long long l,long long r){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k);
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        ld=sumquery(a,b,k*2+1,l,(l+r)/2);
        rd=sumquery(a,b,k*2+2,(l+r)/2,r);
        lp=0;rp=0;
        md=ld+rd;
        md%=mod;
        return md;
    }
}

int main(void){
    sinit();
    long long i,j,n,m,w,x=llinf;
    long long f[524288];
    long long np[524288];
    sd dat[524288];
    char s[524288];
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++){
      scanf("%lld",&f[i]);
      dat[i].val=f[i];
      dat[i].node=i;
    }
    for(i=0;i<m;i++){
      dat[n+i].val=i+1;
      dat[n+i].node=n;
    }
    qsort(dat,n+m,sizeof(dat[0]),sdsortfnc);
    for(i=0;i<n+m;i++){
      if(dat[i].node!=n){
        np[dat[i].node]=dat[i+1].node;
      }
    }
    for(i=n-1;i>=0;i--){
      x=llmin(x,np[i]);
      np[i]=x;
    }
    upd(0,1);
    for(i=0;i<=n;i++){
      w=sumquery(i,i+1,0,0,ssize);
      //printf("%lld %lld %lld\n",i,np[i],w);
      if(i==n){printf("%lld\n",w);}
      else{addquery(i+1,np[i]+1,w,0,0,ssize);}
    }
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
./Main.c:64:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:225:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:227:7: warni...