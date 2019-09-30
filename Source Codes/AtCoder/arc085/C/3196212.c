//Dinic-maxflow
//ABC010-D
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

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

typedef struct{
long long val;
long long node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

sd q[1048576];
long long qp=0,qqp=0;

void qpush(sd x){
    qp++;q[qp]=x;
}

sd qpop(){
    qqp++;
    return q[qqp];
}

typedef struct{
    long long st;
    long long fi;
    long long cap;
    long long id;
    long long rev;
}rs;

typedef struct{
    long long st;
    long long kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st > ((rs*)b)->st){return 1;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
if(((rs*)a)->fi > ((rs*)b)->fi){return 1;}
if(((rs*)a)->fi < ((rs*)b)->fi){return -1;}
return 0;
}

int revsortfnc(const void *a,const void *b){
long long p,q,r,s,t;
p=((rs*)a)->st;
q=((rs*)a)->fi;
r=((rs*)b)->st;
s=((rs*)b)->fi;
if(p>q){t=p;p=q;q=t;}
if(r>s){t=r;r=s;s=t;}
if(p<r){return -1;}
if(p>r){return 1;}
if(q<s){return -1;}
if(q>s){return 1;}
return 0;
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

long long rep(long long vst,long long vfi,long long nf,rs g[],mkj x[],long long dist[],long long ptr[]){
  long long d;
  if(vst==vfi){return nf;}
  while(ptr[vst]<x[vst].kz){
    if(g[x[vst].st+ptr[vst]].cap>0 && dist[vst] < dist[g[x[vst].st+ptr[vst]].fi]){
      d=rep(g[x[vst].st+ptr[vst]].fi,vfi,llmin(nf,g[x[vst].st+ptr[vst]].cap),g,x,dist,ptr);
      if(d>0){
        g[x[vst].st+ptr[vst]].cap-=d;
        g[g[x[vst].st+ptr[vst]].rev].cap+=d;
        return d;
      }
    }
    ptr[vst]++;
  }
  return 0;
}

long long dinic(long long vst,long long vfi,long long vc,long long ec,rs g[],mkj x[]){
  long long nv,i,j,res=0,fl,dist[524288],ptr[524288],f;
  sd pd,od;
  while(1){
    qp=0;qqp=0;
    pd.val=0;
    pd.node=vst;
    qpush(pd);
    for(i=0;i<=vc;i++){
      dist[i]=llinf;
    }
    while(qp-qqp>0){
      od=qpop();
      if(dist[od.node]!=llinf){continue;}
      dist[od.node]=od.val;
      nv=od.node;
      for(i=x[nv].st;i<x[nv].st+x[nv].kz;i++){
        if(dist[g[i].fi]==llinf && g[i].cap>0){
          pd.node=g[i].fi;
          pd.val=od.val+1;
          qpush(pd);
        }
      }
    }
    if(dist[vfi]==llinf){return res;}
    for(i=0;i<=ec;i++){
      ptr[i]=0;
    }
    while(1){
      f=rep(vst,vfi,llinf,g,x,dist,ptr);
      if(f==0){break;}
      res+=f;
    }
  }
}

int main(void){
    long long i,j,n,m,k,a,b,c,h,w=0,r=0,l,t;
    long long p,q;
    rs g[524288];
    mkj x[524288];
    long long cnt=0;
    double d;
    char s[524288];
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld\n",&t);
        if(t>0){
            w+=t;
            p=0;
            q=t;
        }
        else{
            p=-t;
            q=0;
        }
        g[cnt].st=0;
        g[cnt].fi=i;
        g[cnt].cap=p;
        cnt++;
        g[cnt].st=i;
        g[cnt].fi=0;
        g[cnt].cap=0;
        cnt++;
        g[cnt].st=i;
        g[cnt].fi=n+1;
        g[cnt].cap=q;
        cnt++;
        g[cnt].st=n+1;
        g[cnt].fi=i;
        g[cnt].cap=0;
        cnt++;
    }
    for(i=1;i<=n;i++){
        for(j=2*i;j<=n;j+=i){
            g[cnt].st=i;
            g[cnt].fi=j;
            g[cnt].cap=llinf;
            cnt++;
            g[cnt].st=j;
            g[cnt].fi=i;
            g[cnt].cap=0;
            cnt++;
        }
    }
    qsort(g,cnt,sizeof(g[0]),sortfnc);
    for(i=0;i<cnt;i++){
      g[i].id=i;
    }
    qsort(g,cnt,sizeof(g[0]),revsortfnc);
    for(i=0;i<cnt;i+=2){
      g[i].rev=g[i+1].id;
      g[i+1].rev=g[i].id;
    }
    qsort(g,cnt,sizeof(g[0]),sortfnc);
    makemkj(g,x,cnt);
    r=dinic(0,n+1,n+2,cnt,g,x);
    printf("%lld\n",w-r);
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
./Main.c:215:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:217:9: warning: ign...