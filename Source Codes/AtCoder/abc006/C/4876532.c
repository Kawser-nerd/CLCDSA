/***********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <limits.h>
#define MOD 1000000007
#define PI 3.14159265358979323846
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define REP(n) for(int REP_i=0;REP_i<n;REP_i++)
#define SORTU(a,n) qsort(a,n,sizeof(int),cmpu)
#define LSORTU(a,n) qsort(a,n,sizeof(long int),lcmpu)
#define LLSORTU(a,n) qsort(a,n,sizeof(long long int),llcmpu)
#define DSORTU(a,n) qsort(a,n,sizeof(double),dcmpu)
#define CSORTU(a,n) qsort(a,n,sizeof(char),ccmpu)
#define SSORTU(a,n) qsort(a,n,sizeof(a[0]),scmpu)
#define SORTD(a,n) qsort(a,n,sizeof(int),cmpd)
#define LSORTD(a,n) qsort(a,n,sizeof(long int),lcmpd)
#define LLSORTD(a,n) qsort(a,n,sizeof(long long int),llcmpd)
#define DSORTD(a,n) qsort(a,n,sizeof(double),dcmpd)
#define CSORTD(a,n) qsort(a,n,sizeof(char),ccmpd)
#define SSORTD(a,n) qsort(a,n,sizeof(a[0]),scmpd)
int cmpu(const void *a,const void *b){return *(int*)a-*(int*)b;}
int lcmpu(const void *a,const void *b){return *(long int*)a-*(long int*)b;}
int llcmpu(const void *a,const void *b){return *(long long int*)a-*(long long int*)b;}
int dcmpu(const void *a,const void *b){return *(double*)a-*(double*)b;}
int ccmpu(const void *a,const void *b){return *(char*)a-*(char*)b;}
int scmpu(const void *a,const void *b){return strcmp(a,b);}
int cmpd(const void *a,const void *b){return *(int*)b-*(int*)a;}
int lcmpd(const void *a,const void *b){return *(long int*)b-*(long int*)a;}
int llcmpd(const void *a,const void *b){return *(long long int*)b-*(long long int*)a;}
int dcmpd(const void *a,const void *b){return *(double*)b-*(double*)a;}
int ccmpd(const void *a,const void *b){return *(char*)b-*(char*)a;}
int scmpd(const void *a,const void *b){return strcmp(b,a);}
/***********************************************************************************************************************/
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    if(m>=2*n+1 && m<=4*n-1 && m%2==1) printf("%d 1 %d\n",(4*n-m-1)/2,(m-2*n-1)/2);
    else if(m>=2*n && m<=4*n && m%2==0) printf("%d 0 %d\n",(4*n-m)/2,(m-2*n)/2);
    else printf("-1 -1 -1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^