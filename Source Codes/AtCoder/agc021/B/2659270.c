//set many funcs template
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384


long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
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

int main(void){
    srand(time(0));
    long long i,j,n,m,a=0,b[128]={0},c,w,r=0,l,t,x[128],y[128],ni;
    clock_t stt,nt;
    double res,st,k,na,nx,ny,fx[128],fy[128];
    double d;
    char s[262144];
    scanf("%lld",&n);
    //l=strlen(s);
    for(i=0;i<n;i++){scanf("%lld%lld",&x[i],&y[i]);fx[i]=x[i];fy[i]=y[i];}
    for(j=0;j<2000000;j++){
      st=j;st/=2000000.0f;st*=(2.0f*pi);
      ni=-1;na=(double)1e100;
      nx=sin(st);nx*=(double)1e11;
      ny=cos(st);ny*=(double)1e11;
      for(i=0;i<n;i++){
        k=dbzt(nx,fx[i])*dbzt(nx,fx[i])+dbzt(ny,fy[i])*dbzt(ny,fy[i]);
        if(k<na){na=k;ni=i;}
      }
      a++;b[ni]++;
    }
    for(i=0;i<n;i++){
      res=b[i];
      printf("%.12lf\n",res/a);
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    //printf("%d\n",r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:45:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++){scanf("%lld%lld",&x[i],&y[i]);fx[i]=x[i];fy[i]=y[i];}
                      ^