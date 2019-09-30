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
long long from;
}data;
 
data heap[1048576];
long long hsize=0;
 
void resheap(){
    long long i;
    heap[0].node=-1;
    heap[0].cost=-llinf;
    for(i=1;i<1048576;i++){
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
    resheap();
    long long i,j,n,m,s,t,u,v,d,p,q,sd,avalon;
    long long sst,sft,tst,tft;
    long long sw=0,tw=0,dw=0;
    long long ss[524288],ts[524288];
    long long sp[524288]={0},tp[524288]={0};
    bool sef[524288]={0},tef[524288]={0};
    data pd,od;
    rs g[524288];
    mkj x[524288];
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    for(i=0;i<m;i++){
      scanf("%lld%lld%lld",&u,&v,&d);
      g[2*i].st=u;
      g[2*i].fi=v;
      g[2*i].kr=d;
      g[2*i+1].st=v;
      g[2*i+1].fi=u;
      g[2*i+1].kr=d;
    }
    for(i=0;i<=n;i++){
      ss[i]=llinf;
      ts[i]=llinf;
    }
    qsort(g,2*m,sizeof(g[0]),sortfnc);
    makemkj(g,x,2*m);
    pd.node=s;
    pd.cost=0;
    pd.from=-1;
    pqpush(pd);
    while(hsize>0){
      od=pqpop();
      if(ss[od.node]<od.cost){continue;}
      ss[od.node]=od.cost;
      if(od.from==-1){
        sp[od.node]++;
        sp[od.node]%=mod;
      }
      else{
        sp[od.node]+=sp[od.from];
        sp[od.node]%=mod;
      }
      for(i=x[od.node].st;i<x[od.node].st+x[od.node].kz;i++){
        if(ss[g[i].fi]!=llinf || sef[i]==1){continue;}
        sef[i]=1;
        pd.node=g[i].fi;
        pd.cost=od.cost+g[i].kr;
        pd.from=od.node;
        pqpush(pd);
      }
    }
    pd.node=t;
    pd.cost=0;
    pd.from=-1;
    pqpush(pd);
    while(hsize>0){
      od=pqpop();
      if(ts[od.node]<od.cost){continue;}
      ts[od.node]=od.cost;
      if(od.from==-1){
        tp[od.node]++;
        tp[od.node]%=mod;
      }
      else{
        tp[od.node]+=tp[od.from];
        tp[od.node]%=mod;
      }
      for(i=x[od.node].st;i<x[od.node].st+x[od.node].kz;i++){
        if(ts[g[i].fi]!=llinf || tef[i]==1){continue;}
        tef[i]=1;
        pd.node=g[i].fi;
        pd.cost=od.cost+g[i].kr;
        pd.from=od.node;
        pqpush(pd);
      }
    }
    //for(i=1;i<=n;i++){printf("<%lld> sp:%lld tp:%lld\n",i,sp[i],tp[i]);}
    sd=ss[t];
    //printf("mindist:%lld\n",sd);
    if(sd%2==0){
      for(i=1;i<=n;i++){
        if(ss[i]==(sd/2) && ts[i]==(sd/2)){
          sw+=sp[i];
          sw%=mod;
          tw+=tp[i];
          tw%=mod;
          avalon=(sp[i]*tp[i]);
          avalon%=mod;
          avalon*=avalon;
          avalon%=mod;
          dw+=avalon;
          dw%=mod;
          //printf("%lld\n",avalon);
          //printf("%lld:%lld %lld\n",i,sp[i],tp[i]);
        }
      }
    }
    for(i=0;i<2*m;i++){
      p=g[i].st;
      q=g[i].fi;
      if(sd%2==0){
        if(ss[p]==sd/2 || ss[q]==sd/2){continue;}
        if(ts[p]==sd/2 || ts[q]==sd/2){continue;}
      }
      if(ss[p]+g[i].kr+ts[q]==sd){
        sst=ss[p];
        sft=ss[q];
        tst=ts[q];
        tft=ts[p];
        if(sft<tst || tft<sst){continue;}
        sw+=sp[p];
        sw%=mod;
        tw+=tp[q];
        tw%=mod;
        avalon=(sp[p]*tp[q]);
        avalon%=mod;
        avalon*=avalon;
        avalon%=mod;
        dw+=avalon;
        dw%=mod;
        //printf("%lld\n",avalon);
        //printf("%lld %lld:[%lld %lld]\n",p,q,sp[p],tp[q]);
      }
    }
    //printf("%lld %lld\n",sp[t],tp[s]);
    printf("%lld\n",((sp[t]*tp[s])%mod+mod-dw)%mod);
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
./Main.c: In function ‘main’:
./Main.c:162:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
     ^
./Main.c:164:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld%lld",&u,&v,&d);
       ^