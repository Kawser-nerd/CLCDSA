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

typedef struct{
long long x;
long long y;
}dat;

dat q[1048576];
long long qp=0,qqp=0;

void qpush(dat x){
    qp++;q[qp]=x;
}

dat qpop(){
    qqp++;
    return q[qqp];
}

int main(void){
    long long i,j,h,w,a[1024][1024],f[1024][1024]={0},r[1024][1024]={0},res=0,l;
    long long nx,ny;
    double d;
    char s[262144];
    dat p;
    scanf("%lld%lld",&h,&w);
    //l=strlen(s);
    for(i=0;i<=h+1;i++){
        for(j=0;j<=w+1;j++){
            if(i==0||i==h+1||j==0||j==w+1){a[i][j]=-llinf;continue;}
            scanf("%lld\n",&a[i][j]);
        }
    }
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(a[i][j-1]>a[i][j]){f[i][j]++;}
            if(a[i][j+1]>a[i][j]){f[i][j]++;}
            if(a[i-1][j]>a[i][j]){f[i][j]++;}
            if(a[i+1][j]>a[i][j]){f[i][j]++;}
            if(f[i][j]==0){p.x=i;p.y=j;qpush(p);}
        }
    }
    while(qp-qqp){
        p=qpop();
        //printf("pop:%lld %lld\n",p.x,p.y);
        nx=p.x;ny=p.y;
        r[nx][ny]++;r[nx][ny]%=mod;
        for(i=nx-1;i<=nx+1;i++){
        for(j=ny-1;j<=ny+1;j++){
        if(!(1<=i && i<=h && 1<=j && j<=w)){continue;}
        if((llzt(nx,i)+llzt(ny,j))!=1){continue;}
        if(a[i][j]>a[nx][ny]){
            r[nx][ny]+=r[i][j];r[nx][ny]%=mod;
        }
        if(a[i][j]<a[nx][ny]){
            f[i][j]--;
            //printf("%lld %lld:%lld\n",i,j,f[i][j]);
            if(f[i][j]==0){p.x=i;p.y=j;qpush(p);}
        }
        }
        }
    }
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            res+=r[i][j];res%=mod;
            //printf("%lld\n",r[i][j]);
        }
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
./Main.c:64:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&h,&w);
     ^
./Main.c:69:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%lld\n",&a[i][j]);
             ^