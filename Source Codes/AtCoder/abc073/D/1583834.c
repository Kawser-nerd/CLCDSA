// debug for https://beta.atcoder.jp/contests/abc073/submissions/1583069

//set many funcs
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf 1145141919
#define llinf 1145141919810364364
#define mod 1000000007

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
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}

long long dfs(long long np,long long tf[16],long long rk,long long cr[16][16],long long nc,long long* ans){
    long long i=0,j,f=1,dr,stf[16]={0};
    while(1){
        i++;if(i>rk){break;}
        if(tf[i] == 0){
            f=0;
            tf[i]=1;
            dr=dfs(i,tf,rk,cr,nc+cr[np][i],ans);
            tf[i]=0;
        }
    }
    if(f==1){*ans=min(*ans,nc);}
    return 0;
}

int main(void){
    long long dr,n,m,r,rl[16],i,j,k,w[256][256],a,b,c,rw[16][16],tf[16]={0},zr,res;
    scanf("%lld%lld%lld",&n,&m,&r);
    for(i=1;i<=r;i++){scanf("%lld",&rl[i]);}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)w[i][j]=inf>>1; // added
    for(i=1;i<=m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        /*w[a][b]=c;w[b][a]=c;*/w[a][b]=w[b][a]=min(w[a][b],c); // changed
    }
    for(i=1;i<=n;i++){w[i][i]=0;}
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(i>r||j>r){rw[i][j]=inf;}
            else{rw[i][j]=w[rl[i]][rl[j]];}
        }
    }
    res=inf;
    for(i=1;i<=r;i++){
        for(j=0;j<=15;j++){tf[j]=0;}
        zr=inf;
        tf[i]=1;
        dr = dfs(i,tf,r,rw,0,&zr);
        res=llmin(zr,res);
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
./Main.c:23:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:56:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&n,&m,&r);
     ^
./Main.c:57:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=r;i++){scanf("%lld",&rl[i]);}
                       ^
./Main.c:60:9: warning...