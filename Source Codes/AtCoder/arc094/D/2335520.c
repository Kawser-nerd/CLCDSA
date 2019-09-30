#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf 1072114514
#define llinf 1145141919810364364
#define mod 998244353

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

int main(void){
    long long i,j,k,l,r=1,pm=0,nr,dp[262144][2][4][4]={0};//dp[pod][fl][mod][bw]
    char s[262144];
    scanf("%s",s);
    l=strlen(s);
    for(i = 1;i < l;i++){
        if(s[i]!=s[0]){break;}
        if(i==l-1){printf("1\n");return 0;}
    }
    if(l==2){
        printf("2\n");return 0;
    }
    if(l==3){
        if(s[0]==s[1] && s[1]!=s[2]){printf("6\n");return 0;}
        if(s[0]==s[2] && s[0]!=s[1]){printf("7\n");return 0;}
        if(s[0]!=s[1] && s[1]==s[2]){printf("6\n");return 0;}
        printf("3\n");return 0;
    }
    for(i=0;i<l;i++){pm+=(s[i]-'a');
        if(i!=0){if(s[i]==s[i-1]){r=0;}}
    }pm%=3;
    dp[1][0][0][0]=1;
    dp[1][0][1][1]=1;
    dp[1][0][2][2]=1;
    for(i=2;i<=l;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                for(nr=0;nr<3;nr++){
                    if(k==nr){
                        dp[i][1][(j+nr)%3][nr]+=dp[i-1][0][j][k];dp[i][1][(j+nr)%3][nr]%=mod;
                        dp[i][1][(j+nr)%3][nr]+=dp[i-1][1][j][k];dp[i][1][(j+nr)%3][nr]%=mod;
                    }
                    else{
                        dp[i][0][(j+nr)%3][nr]+=dp[i-1][0][j][k];dp[i][0][(j+nr)%3][nr]%=mod;
                        dp[i][1][(j+nr)%3][nr]+=dp[i-1][1][j][k];dp[i][1][(j+nr)%3][nr]%=mod;
                    }
                    //printf("[%lld]",dp[i][1][(j+nr)%3][nr]);
                }
            }
        }
    }
    for(i=0;i<3;i++){
        //printf("<%lld>\n",dp[l][1][pm][i]);
        r+=dp[l][1][pm][i];r%=mod;
    }
    printf("%lld\n",r);
    return 0;
} ./Main.c:11:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:12:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:17:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:21:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^