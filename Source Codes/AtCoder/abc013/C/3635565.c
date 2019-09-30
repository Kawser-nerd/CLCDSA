#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE long long
#define MEMSET(a) memset(a,0,sizeof(a))
const int mod=(int)1e09+7;

long long in(void){
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
void print(long long a){
    printf("%lld\n",a);
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
double dmax(double a,double b){
    return a>b?a:b;
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

int main(void){
    long long i=0,j,n=in(),h=in(),a=in(),b=in(),c=in(),d=in(),e=in(),manpuku,kane,zantei=a*n;  //a,c:?, b,d:???
    if(h>n*e)zantei=0;
    rep(i,n){
        if(b*i+h-(n-i)*e>0){
            kane=a*i;
            if(kane<zantei)zantei=kane;
        }
        else{
            j=(n*e-(b+e)*i-h)/(d+e);
            if(j<=n-i-1&&j>=0){
                j++;
                manpuku=b*i+d*j+h-(n-i-j)*e;
                if(manpuku>0)kane=a*i+c*j;
                if(kane<zantei)zantei=kane;
            }
        }
    }
    print(zantei);
    return 0;
} ./Main.c: In function ‘in’:
./Main.c:21:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     long long i;scanf("%lld",&i);
                 ^
./Main.c: In function ‘din’:
./Main.c:25:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     double i;scanf("%lf",&i);
              ^
./Main.c: In function ‘chin’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^