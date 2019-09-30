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
long long single;
long long score;
long long id;
}smem;

int sortfnc1(const void *a,const void *b){
if(((smem*)a)->single == ((smem*)b)->single){return 0;}
if(((smem*)a)->single < ((smem*)b)->single){return -1;}
return 1;
}

int sortfnc2(const void *a,const void *b){
if(((smem*)a)->score == ((smem*)b)->score){return 0;}
if(((smem*)a)->score < ((smem*)b)->score){return -1;}
return 1;
}

smem fs[524288],ls[524288];

void shuffledget(long long n){
    srand(time(0));
    long long i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%lld%lld",&fs[b[i]].single,&fs[b[i]].score);
        ls[b[i]].single=fs[b[i]].single;
        ls[b[i]].score=fs[b[i]].score;
    fs[b[i]].id=b[i];
    ls[b[i]].id=b[i];
    }
}

long long nm(long long p,smem dat){
    if(dat.single <= p && p <= dat.score){return p;}
    if(p > dat.score){return dat.score;}
    return dat.single;
}

int main(void){
    long long p,i,j,n,m,k,a[524288],b,c,w,r=0,l,t;
    long long r1=0,r2=0;
    long long fl1[524288]={0},fl2[524288]={0};
    double d;
    char s[524288];
    scanf("%lld",&n);
    //l=strlen(s);
    //for(i=0;i<n;i++){scanf("%d",&a[i]);}
    shuffledget(n);
    qsort(fs,n,sizeof(smem),sortfnc1);
    qsort(ls,n,sizeof(smem),sortfnc2);
    p=0;
    for(i=0;i<n;i++){
        //printf("#%d#",i);
        //printf("%lld*",fs[n-1-i].id);
        if(fl1[fs[n-1-i].id]==0){
            fl1[fs[n-1-i].id]=1;
            w=nm(p,fs[n-1-i]);
            r1+=llzt(p,w);
            p=w;
            //printf("<%lld>",r1);
        }
        //printf("%lld*",ls[i].id);
        if(fl1[ls[i].id]==0){
            fl1[ls[i].id]=1;
            w=nm(p,ls[i]);
            r1+=llzt(p,w);
            p=w;
            //printf("<%lld>",r1);
        }
    }
    r1+=llzt(0,p);
    p=0;
    for(i=0;i<n;i++){
        if(fl2[ls[i].id]==0){
            fl2[ls[i].id]=1;
            w=nm(p,ls[i]);
            r2+=llzt(p,w);
            p=w;
            //printf("[%lld]",r2);
        }
        if(fl2[fs[n-1-i].id]==0){
            fl2[fs[n-1-i].id]=1;
            w=nm(p,fs[n-1-i]);
            r2+=llzt(p,w);
            p=w;
            //printf("[%lld]",r2);
        }
    }
    r2+=llzt(0,p);
    printf("%lld\n",llmax(r1,r2));
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
./Main.c: In function ‘shuffledget’:
./Main.c:77:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&fs[b[i]].single,&fs[b[i]].score);
         ^
./Main.c: In function ‘main’:
./Main.c:97:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^...