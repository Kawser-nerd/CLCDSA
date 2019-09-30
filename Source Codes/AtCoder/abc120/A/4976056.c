/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <tgmath.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define MOD 1000000007
#define PI 3.141592653589793238

struct SLN{int D;struct SLN *N;};
struct DLN{int D;struct DLN *N;struct DLN *P;};
struct CLN{int D;struct CLN *N;};
struct AS{int T;int C;int *A;};
struct AQ{int F;int R;int CA;int *A;};
struct BTN{int D;struct BTN *L;struct BTN *R;};
struct GTN{int D;struct GTN *F;struct GTN *N;};
struct TBTN{struct TBTN *L;int LT;int D;int RT;struct TBTN *R;};
struct BSTN{int D;struct BSTN *L;struct BSTN *R;};
struct AVLTN{struct AVLTN *L;int D;struct AVLTN *R;int H;};
struct H{int *A;int C;int CA;int HT;};
struct GM{int V;int E;int **A;};
struct GL{int V;int E;int *A;};
struct HLN{int K;int D;struct HLN *N;};
struct TN{char D;int SE;struct TN *C[26];};
struct TSTN{char D;int SE;struct TSTN *L;struct TSTN *E;struct TSTN *R;};

int *imalloc(int n){return (int*)malloc(sizeof(int)*n);}
int **imalloc2(int n){return (int**)malloc(sizeof(int*)*n);}
long int *lmalloc(int n){return (long int*)malloc(sizeof(long int)*n);}
long int **lmalloc2(int n){return (long int**)malloc(sizeof(long int*)*n);}
long long int *llmalloc(int n){return (long long int*)malloc(sizeof(long long int)*n);}
long long int **llmalloc2(int n){return (long long int**)malloc(sizeof(long long int*)*n);}
double *dmalloc(int n){return (double*)malloc(sizeof(double)*n);}
double **dmalloc2(int n){return (double**)malloc(sizeof(double*)*n);}
char *cmalloc(int n){return (char*)malloc(sizeof(char)*n);}
char **cmalloc2(int n){return (char**)malloc(sizeof(char*)*n);}

int imax(int a,int b){return a>b?a:b;}
long int lmax(long int a,long int b){return a>b?a:b;}
long long int llmax(long long int a,long long int b){return a>b?a:b;}
double dmax(double a,double b){return a>b?a:b;}
char cmax(char a,char b){return a>b?a:b;}
char *smax(char *a,char *b){return strcmp(a,b)>0?a:b;}
int imin(int a,int b){return a<b?a:b;}
long int lmin(long int a,long int b){return a<b?a:b;}
long long int llmin(long long int a,long long int b){return a<b?a:b;}
double dmin(double a,double b){return a<b?a:b;}
char cmin(char a,char b){return a<b?a:b;}
char *smin(char *a,char *b){return strcmp(a,b)<0?a:b;}

int igcd(int a,int b){int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
long int lgcd(long int a,long int b){long int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
long long int llgcd(long long int a,long long int b){long long int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
int ilcm(int a,int b){return a*b/igcd(a,b);}
long int llcm(long int a,long int b){return a*b/lgcd(a,b);}
long long int lllcm(long long int a,long long int b){return a*b/llgcd(a,b);}

int icmpu(const void *a,const void *b){return *(int*)a-*(int*)b;}
int lcmpu(const void *a,const void *b){return *(long int*)a-*(long int*)b;}
int llcmpu(const void *a,const void *b){return *(long long int*)a-*(long long int*)b;}
int dcmpu(const void *a,const void *b){return *(double*)a-*(double*)b;}
int ccmpu(const void *a,const void *b){return *(char*)a-*(char*)b;}
int scmpu(const void *a,const void *b){return strcmp(a,b);}
int icmpd(const void *a,const void *b){return *(int*)b-*(int*)a;}
int lcmpd(const void *a,const void *b){return *(long int*)b-*(long int*)a;}
int llcmpd(const void *a,const void *b){return *(long long int*)b-*(long long int*)a;}
int dcmpd(const void *a,const void *b){return *(double*)b-*(double*)a;}
int ccmpd(const void *a,const void *b){return *(char*)b-*(char*)a;}
int scmpd(const void *a,const void *b){return strcmp(b,a);}

void isortu(int *a,int n){qsort(a,n,sizeof(int),icmpu);}
void lsortu(long int *a,int n){qsort(a,n,sizeof(long int),lcmpu);}
void llsortu(long long int *a,int n){qsort(a,n,sizeof(long long int),llcmpu);}
void dsortu(double *a,int n){qsort(a,n,sizeof(double),dcmpu);}
void csortu(char *a,int n){qsort(a,n,sizeof(char),ccmpu);}
void ssortu(char **a,int n){qsort(a,n,sizeof(a[0]),scmpu);}
void isortd(int *a,int n){qsort(a,n,sizeof(int),icmpd);}
void lsortd(long int *a,int n){qsort(a,n,sizeof(long int),lcmpd);}
void llsortd(long long int *a,int n){qsort(a,n,sizeof(long long int),llcmpd);}
void dsortd(double *a,int n){qsort(a,n,sizeof(double),dcmpd);}
void csortd(char *a,int n){qsort(a,n,sizeof(char),ccmpd);}
void ssortd(char **a,int n){qsort(a,n,sizeof(a[0]),scmpd);}

struct SLN **newsln(void){struct SLN **h=(struct SLN**) malloc(sizeof(struct SLN*));(*h)->N=NULL;return h;}
void iisl(struct SLN **h,int d,int p){int k=1;struct SLN *a,*b,*n;n=(struct SLN*) malloc(sizeof(struct SLN));if(!n) return;n->D=d;a=*h;if(p==1){n->N=a;*h=n;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}b->N=n;n->N=a;}}
void dfsl(struct SLN **h,int p){int k=1;struct SLN *a,*b;if(*h==NULL) return;a=*h;if(p==1){*h=(*h)->N;free(a);return;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}if(a==NULL) return;else{b->N=a->N;free(a);}}}
int sll(struct SLN **h){struct SLN *cu=*h;int c=0;while(cu!=NULL){c++;cu=cu->N;}return c;}

struct GM *newgm(int v){struct GM *G=(struct GM*) malloc(sizeof(struct GM));int i,j;G->V=v;G->A=imalloc2(G->V);for(i=0;i<G->V;i++){G->A[i]=imalloc(G->V);for(j=0;j<G->V;j++){G->A[i][j]=0;}}return G;}

/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b/a>=c) printf("%d\n",c);
    else printf("%d\n",b/a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:102:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^