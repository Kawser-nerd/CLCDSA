//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf 1072114514
#define llinf 4154118101919364364
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
    int h,w,t,i,j,p,q,k,c[16][16][128],f,r=-inf;
    char s[16][16];
    scanf("%d%d%d",&h,&w,&t);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j] == 'S'){
                for(k=0;k<128;k++){c[i][j][k]=0;}
            }
            else{
                for(k=0;k<128;k++){c[i][j][k]=inf;}
            }
        }
    }
    f=1;
    while(f){
        f=0;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                for(p=-1;p<2;p++){
                    for(q=-1;q<2;q++){
                        if(i+p<0 || i+p>=h || j+q<0 || j+q>=w || zt(p,0)+zt(q,0)!=1){continue;}
                        for(k=0;k<127;k++){
                            if(s[i+p][j+q]=='#'){
                                if(c[i+p][j+q][k+1] > c[i][j][k]){c[i+p][j+q][k+1]=c[i][j][k];f=1;}
                            }
                            else{
                                if(c[i+p][j+q][k] > c[i][j][k]+1){c[i+p][j+q][k]=c[i][j][k]+1;f=1;}
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]!='G'){continue;}
            for(k=1;k<127;k++){
                r=max(r,(t-c[i][j][k])/k);
            }
        }
    }
    printf("%d\n",r);
    return 0;
} ./Main.c:12:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:13:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:18:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:22:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&h,&w,&t);
     ^
./Main.c:44:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^