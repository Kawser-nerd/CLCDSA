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

int bsum[2048][2048]={0};
int wsum[2048][2048]={0};

int cbz(int fx,int fy,int tx,int ty){
    if(fx>tx || fy>ty){return 0;}
    if(fx==0 && fy == 0){return bsum[tx][ty];}
    else if(fx==0){
        return bsum[tx][ty]-bsum[tx][fy-1];
    }
    else if(fy==0){
        return bsum[tx][ty]-bsum[fx-1][ty];
    }
    else{
        return bsum[tx][ty]-bsum[tx][fy-1]-bsum[fx-1][ty]+bsum[fx-1][fy-1];
    }
}

int cwz(int fx,int fy,int tx,int ty){
    if(fx>tx || fy>ty){return 0;}
    if(fx==0 && fy == 0){return wsum[tx][ty];}
    else if(fx==0){
        return wsum[tx][ty]-wsum[tx][fy-1];
    }
    else if(fy==0){
        return wsum[tx][ty]-wsum[fx-1][ty];
    }
    else{
        return wsum[tx][ty]-wsum[tx][fy-1]-wsum[fx-1][ty]+wsum[fx-1][fy-1];
    }
}

int main(void){
    int i,j,n,k,dk,x,y,r=0,l,kr;
    int bf[2048][2048]={0};
    int wf[2048][2048]={0};
    double d;
    char s[262144],c[2];
    scanf("%d%d",&n,&k);
    dk=k*2;
    //l=strlen(s);
    for(i=1;i<=n;i++){
        scanf("%d %d %s",&x,&y,c);
        if(c[0]=='B'){bf[x%dk][y%dk]++;}
        else{wf[x%dk][y%dk]++;}
    }
    for(i=0;i<dk;i++){
        for(j=0;j<dk;j++){
            if(j==0){
                bsum[i][j]=bf[i][j];
                wsum[i][j]=wf[i][j];
            }
            else{
                bsum[i][j]=bsum[i][j-1]+bf[i][j];
                wsum[i][j]=wsum[i][j-1]+wf[i][j];
            }
        }
    }
    for(i=0;i<dk;i++){
        for(j=0;j<dk;j++){
            if(i!=0){
                bsum[i][j]=bsum[i-1][j]+bsum[i][j];
                wsum[i][j]=wsum[i-1][j]+wsum[i][j];
            }
        }
    }
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            kr=cbz(0,0,i-1,j-1);
            kr+=cwz(i,0,i+k-1,j-1);
            kr+=cbz(i+k,0,dk-1,j-1);
            kr+=cwz(0,j,i-1,j+k-1);
            kr+=cbz(i,j,i+k-1,j+k-1);
            kr+=cwz(i+k,j,dk-1,j+k-1);
            kr+=cbz(0,j+k,i-1,dk-1);
            kr+=cwz(i,j+k,i+k-1,dk-1);
            kr+=cbz(i+k,j+k,dk-1,dk-1);
            r=max(kr,r);
        }
    }
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            kr=cwz(0,0,i-1,j-1);
            kr+=cbz(i,0,i+k-1,j-1);
            kr+=cwz(i+k,0,dk-1,j-1);
            kr+=cbz(0,j,i-1,j+k-1);
            kr+=cwz(i,j,i+k-1,j+k-1);
            kr+=cbz(i+k,j,dk-1,j+k-1);
            kr+=cwz(0,j+k,i-1,dk-1);
            kr+=cbz(i,j+k,i+k-1,dk-1);
            kr+=cwz(i+k,j+k,dk-1,dk-1);
            r=max(kr,r);
        }
    }
    printf("%d\n",r);
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
./Main.c:80:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:84:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %s",&x,&y,c);
         ^