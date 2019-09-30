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
 
long long m;
 
long long nhiu(long long a,long long b,long long x){
    if(a>b){
        if((a <= x && x <= m) || (1 <= x && x < b)){return 1;}
    }
    else{if(a <= x && x < b){return 1;}}
    return 0;
}
 
long long sth(long long a,long long b,long long x){
    long long r1,r2;
    if(a>b){r1=(b+m)-a;}else{r1=b-a;}
    if(x>b){r2=(b+m)-x+1;}else{r2=b-x+1;}
    return llmin(r1,r2);
}
 
long long mm(long long x){
    long long r;
    r=x%m;
    if(r==0){return m;}else{return r;}
}
 
int main(void){
    long long i,j,n,a[131072],b[131072]={0},dd[131072]={0},fd=0,fr=0,r;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++){scanf("%lld",&a[i]);
        if(2<=i){
            b[a[i]]+=((a[i]+m-a[i-1]-1)%m);
            dd[mm(a[i-1]+2)]++;
            dd[mm(a[i]+1)]--;
            //printf("{%lld %lld}\n",mm(a[i-1]+2),mm(a[i]+1));
            fd+=nhiu(mm(a[i-1]+2),mm(a[i]+1),1);
            //printf("+%lld+\n",nhiu(mm(a[i-1]+2),mm(a[i]+1),1));
            fr+=sth(a[i-1],a[i],1);
        }
    }
    //printf("%lld\n",fd);
    r=fr;
    for(i=2;i<=m;i++){
        //printf("<%lld %lld>",dd[i],b[i-1]);
        fr+=b[i-1];
        fd+=dd[i];
        fr-=fd;
        r=llmin(r,fr);
        //printf("%lld %lld\n",fd,fr);
    }
    printf("%lld\n",r);
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
./Main.c:66:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:67:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=n;i++){scanf("%lld",&a[i]);
                       ^