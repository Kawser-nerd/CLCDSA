//set many funcs template
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
    int par;
    int dep;
}node;

node uft[524288];

void resuf(){
    int i;
    for(i=0;i<524288;i++){
        uft[i].par=i;uft[i].dep=0;
    }
    return;
}

int find(int x){
    if(uft[x].par==x){return x;}
    else{uft[x].par=find(uft[x].par);return uft[x].par;}
}

void uni(int x,int y){
    int xp,yp;
    xp=find(x);yp=find(y);
    if(xp==yp){return;}
    if(uft[xp].dep>uft[yp].dep){
        uft[yp].par=xp;
    }
    else{
        uft[xp].par=yp;
        if(uft[xp].dep==uft[yp].dep){uft[yp].dep++;}
    }
    return;
}

typedef struct{
    int st;
    int no;
    int pod;
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

void makemkj(rs g[],mkj x[],long long n){
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

int main(void){
    resuf();
    int i,j,n,m,k,a[262144],b,c,w,r=0,l,t;
    int ck[262144]={0};
    int xx,yy;
    rs dat[262144];
    mkj x[262144];
    double d;
    char s[262144];
    scanf("%d%d",&n,&m);
    //l=strlen(s);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}
    for(j=1;j<=m;j++){scanf("%d%d",&xx,&yy);
    //printf("%d %d\n",&xx,&yy);
    uni(xx,yy);
    }
    for(i=1;i<=n;i++){//printf("%d\n",find(i));
        dat[i-1].st=find(i);
        dat[i-1].no=a[i];
        dat[i-1].pod=i;
    }
    qsort(dat,n,sizeof(rs),sortfnc);
    makemkj(dat,x,n);
    for(i=1;i<=n;i++){
        if(x[i].kz == 0){continue;}
        for(j=x[i].st;j<x[i].st+x[i].kz;j++){
            //printf("%d %d ",dat[j].no,dat[j].pod);
            ck[dat[j].no]++;
            if(ck[dat[j].no]==2){ck[dat[j].no]=0;r++;}
            ck[dat[j].pod]++;
            if(ck[dat[j].pod]==2){ck[dat[j].pod]=0;r++;}
        }
        for(j=x[i].st;j<x[i].st+x[i].kz;j++){
            ck[dat[j].no]=0;
            ck[dat[j].pod]=0;
        }
    }
    printf("%d\n",r);
    return 0;
} ./Main.c:15:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:16:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:22:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:26:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:119:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:121:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=n;i++){scanf("%d",&a[i]);}
                       ^
./Main.c:122:23: warning: ignoring...