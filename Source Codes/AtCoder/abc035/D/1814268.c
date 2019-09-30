//Heap and Priority queue
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

data heap[16777216];
long long hsize=0;

void resheap(){
    long long i;
    heap[0].node=-1;
    heap[0].cost=-llinf;
    for(i=1;i<262144;i++){
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

int main(void){
    long long i,j,n,m,t,la[262144];
    long long a[262144],b[262144],c[262144];
    long long stgo[262144],stbk[262144];
    bool gof[262144],bkf[262144];
    rs ggo[262144],gbk[262144];
    mkj mggo[262144],mgbk[262144];
    data hjm,nn,pd;
    long long res=-llinf;
    resheap();
    hjm.node=1;hjm.cost=0;
    scanf("%lld%lld%lld",&n,&m,&t);
    for(i=1;i<=n;i++){
        scanf("%lld",&la[i]);
        stgo[i]=llinf;stbk[i]=llinf;
        gof[i]=false;bkf[i]=false;
    }
    for(i=0;i<m;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        ggo[i].st=a[i];ggo[i].fi=b[i];ggo[i].kr=c[i];
        gbk[i].st=b[i];gbk[i].fi=a[i];gbk[i].kr=c[i];
    }
    qsort(ggo,m,sizeof(rs),sortfnc);
    qsort(gbk,m,sizeof(rs),sortfnc);
    makemkj(ggo,mggo,2*m);
    makemkj(gbk,mgbk,2*m);
    pqpush(hjm);
    while(hsize){
        nn=pqpop();
        if(gof[nn.node]==true){continue;}
        gof[nn.node]=true;
        stgo[nn.node]=nn.cost;
        for(i=mggo[nn.node].st;i<mggo[nn.node].st+mggo[nn.node].kz;i++){
            if(gof[ggo[i].fi]==true){continue;}
            pd.node=ggo[i].fi;
            pd.cost=nn.cost+ggo[i].kr;
            pqpush(pd);
        }
    }
    pqpush(hjm);
    while(hsize){
        nn=pqpop();
        if(bkf[nn.node]==true){continue;}
        bkf[nn.node]=true;
        stbk[nn.node]=nn.cost;
        for(i=mgbk[nn.node].st;i<mgbk[nn.node].st+mgbk[nn.node].kz;i++){
            if(bkf[gbk[i].fi]==true){continue;}
            pd.node=gbk[i].fi;
            pd.cost=nn.cost+gbk[i].kr;
            pqpush(pd);
        }
    }
    for(i=1;i<=n;i++){
        if(stgo[i]==llinf || stbk[i]==llinf){continue;}
        res=llmax(res,la[i]*(t-stgo[i]-stbk[i]));
    }
    printf("%lld\n",res);
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
./Main.c:149:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&n,&m,&t);
     ^
./Main.c:151:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&la[i]);
         ^
./Main.c:156:9: warning: ignoring return value of ...