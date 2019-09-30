#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>    
#define inf 100000000
#define INF 9223372036854775807
#define EPS 1e-10
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE int
#define MEMSET(a) memset(a,0,sizeof(a))
long long mod=(long long)1e09+7;

int in(void){
    int i;scanf("%d",&i);
    return i;
}
long long llin(void){
    long long i;scanf("%lld",&i);
    return i;
}
double din(void){
    double i;scanf("%lf",&i);
    return i;
}
void chin(char s[]){
    scanf("%s",s);
}
void print(int a){
    printf("%d\n",a);
}
void llprint(long long a){
    printf("%lld\n",a);
}
void dprint(double a){
    printf("%.10f\n",a);
}
void print2(int a,int b){
    printf("%d %d\n",a,b);
}
long long max(long long a,long long b){
    return a>b?a:b;
}
long long min(long long a,long long b){
    return a<b?a:b;
}
int cmp(const void *a,const void *b){
    return *(TYPE *)a-*(TYPE *)b;
}
int cmp_r(const void *a,const void *b){
    return *(TYPE *)b-*(TYPE *)a;
}
int char_cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
int char_cmp_r(const void *a,const void *b){
    return strcmp((char *)b,(char *)a);
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
long long gcd(long long x,long long y){
    return x%y?gcd(y,x%y):y;
}
long long lcm(long long x,long long y){
    return x/gcd(x,y)*y;
}

// write codes below this
// when you use 'sort',
// make sure TYPE macro is correct

long long modpow(long long x,long long n) {
    long long result = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
 
    return result;
}
#define N 3*1000000
long long x[N+1],y[N+1];

void make_fact_table(int n){
    int i;
    x[0]=y[0]=1;
    for(i=1;i<=n;i++){
        x[i]=(long long)(x[i-1]*i)%mod;
        y[i]=modpow(x[i],mod-2);
    }
}

long long mod_nCr(int n, int r){
    return x[n]*y[n-r]%mod*y[r]%mod;
}

int main(void){
    long long n=llin(),a=llin(),b=llin(),k=llin(),i,ans=0;
    mod=998244353;
    make_fact_table(n);
    rep(i,n+1){
        if(k-i*a<0)continue;
        if((k-i*a)%b==0){
            long long x=i,y=(k-i*a)/b;
            ans=(ans+mod_nCr(n,x)*mod_nCr(n,y)%mod)%mod;
        }
    }
    llprint(ans);
    return 0;
} ./Main.c: In function ‘in’:
./Main.c:23:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int i;scanf("%d",&i);
           ^
./Main.c: In function ‘llin’:
./Main.c:27:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     long long i;scanf("%lld",&i);
                 ^
./Main.c: In function ‘din’:
./Main.c:31:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     double i;scanf("%lf",&i);
              ^
./Main.c: In function ‘chin’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^