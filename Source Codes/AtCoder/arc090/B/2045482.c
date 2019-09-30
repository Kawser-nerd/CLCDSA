//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
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
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
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

long long q[1048576];
long long qp=0,qqp=0;

void qpush(long long x){
    qp++;q[qp]=x;
}

long long qpop(){
    qqp++;
    return q[qqp];
}

int main(void){
    long long rp,i,j,n,m,t,k,l,r,d,df[262144]={0},zv=0;
    long long a[262144];
    long long sn;
    rs g[524288];
    mkj x[524288];
    //double d;
    //char s[262144];
    scanf("%lld%lld",&n,&m);
    //l=strlen(s);
    for(i=1;i<=n;i++){
        a[i]=-llinf;
    }
    for(i=0;i<m;i++){
        scanf("%lld%lld%lld",&l,&r,&d);
        df[l]=1;df[r]=1;
        g[2*i].st=l;
        g[2*i].fi=r;
        g[2*i].kr=d;
        g[2*i+1].st=r;
        g[2*i+1].fi=l;
        g[2*i+1].kr=-d;
    }
    for(i=1;i<=n;i++){
        zv+=df[i];
    }
    qsort(g,2*m,sizeof(rs),sortfnc);
    makemkj(g,x,2*m);
    a[g[0].st]=0;a[g[0].fi]=g[0].kr;
    qpush(g[0].st);
    qpush(g[0].fi);
    zv-=2;rp=1;
    while(qp-qqp || zv>0){
        sn=qpop();
    for(i=x[sn].st;i<x[sn].st+x[sn].kz;i++){
        if(a[g[i].st]!=-llinf && a[g[i].fi]!=-llinf){
            if(a[g[i].fi]-a[g[i].st] != g[i].kr){printf("No\n");return 0;}
        }
        else if(a[g[i].st] == -llinf){
            a[g[i].st]=a[g[i].fi]-g[i].kr;
            qpush(g[i].st);zv--;
        }
        else{
            a[g[i].fi]=a[g[i].st]+g[i].kr;
            qpush(g[i].fi);zv--;
        }
    }
    if(qp-qqp==0 && zv>0){
        while(1){
            if(a[rp]==-llinf && df[rp]==1){
                a[rp]=0;zv--;
                qpush(rp);break;
            }
            rp++;
        }
    }
    }
    printf("Yes\n");
    return 0;
} ./Main.c:14:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:15:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:20:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:24:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:93:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:99:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld%lld",&l,&r,&d);
         ^