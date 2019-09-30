//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

int b[4][4],c[4][4],ts;

int rep(int nb[4][4],int zh){
    int ra[4][4],i,j,r;
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            ra[i][j]=nb[i][j];
        }
    }
    if(zh == 0){
        for(i=1;i<=2;i++){
            for(j=1;j<=3;j++){
                if(ra[i][j] == ra[i+1][j]){r+=b[i][j];}
            }
        }
        for(i=1;i<=3;i++){
            for(j=1;j<=2;j++){
                if(ra[i][j] == ra[i][j+1]){r+=c[i][j];}
            }
        }
        return r;
    }
    else{
        if(zh%2){r=-inf;}else{r=inf;}
        for(i=1;i<=3;i++){
            for(j=1;j<=3;j++){
                if(ra[i][j] != 0){continue;}
                if(zh%2){ra[i][j]=1;r=max(r,rep(ra,zh-1));}else{ra[i][j]=2;r=min(r,rep(ra,zh-1));}
                ra[i][j]=0;
            }
        }
        return r;
    }
}

int main(void){
    int nb[4][4]={0},ck;
    scanf("%d%d%d",&b[1][1],&b[1][2],&b[1][3]);
    scanf("%d%d%d",&b[2][1],&b[2][2],&b[2][3]);
    scanf("%d%d",&c[1][1],&c[1][2]);
    scanf("%d%d",&c[2][1],&c[2][2]);
    scanf("%d%d",&c[3][1],&c[3][2]);
    ts=b[1][1]+b[1][2]+b[1][3]+b[2][1]+b[2][2]+b[2][3]+c[1][1]+c[1][2]+c[2][1]+c[2][2]+c[3][1]+c[3][2];
    ck=rep(nb,9);
    printf("%d\n%d\n",ck,ts-ck);
    return 0;
} ./Main.c:13:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:14:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:19:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:23:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:77:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&b[1][1],&b[1][2],&b[1][3]);
     ^
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&b[2][1],&b[2][2],&b[2][3]);
     ^
./Main.c:79:5: warning: ig...