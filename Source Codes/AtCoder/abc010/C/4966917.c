/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

//?????
#include <stdio.h>//?????
#include <stdlib.h>//??
#include <ctype.h>//????
#include <string.h>//?????
#include <tgmath.h>//??
#include <stdbool.h>//??
#include <time.h>//??
#include <limits.h>//???

//??
#define MOD 1000000007//??
#define PI 3.141592653589793238//???

//?????
struct SLN{int D;struct SLN *N;};//?????(Single List Node{data,next})
struct DLN{int D;struct DLN *N;struct DLN *P;};//2????(Double List Node{data,next,preview})
struct CLN{int D;struct CLN *N;};//?????(Circulation List Node{data,next})
struct AS{int T;int C;int *A;};//????(Array Stack{top,capacity,array})
struct AQ{int F;int R;int CA;int *A;};//???(Array Queue{front,rear,capacity,array})
struct BTN{int D;struct BTN *L;struct BTN *R;};//2??(Binary Tree Node{data,left,right})
struct GTN{int D;struct GTN *F;struct GTN *N;};//N??(General Tree Node{data,first,next})
struct TBTN{struct TBTN *L;int LT;int D;int RT;struct TBTN *R;};//????2??(Threaded Binary Tree Node{left,left tag,data,right tag,right})
struct BSTN{int D;struct BSTN *L;struct BSTN *R;};//2????(Binary Search Tree Node{data,left,right})
struct AVLTN{struct AVLTN *L;int D;struct AVLTN *R;int H;};//AVL?(AVL Tree Node{left,data,right,height})
struct H{int *A;int C;int CA;int HT;};//???(Heap{array,count,capacity,heap type})
struct GM{int V;int E;int **A;};//????(Graph Matrix{vertice,edge,adjacent})
struct GL{int V;int E;int *A;};//?????(Graph List{vertice,edge,adjacent})
struct HLN{int K;int D;struct HLN *N;};//????(Hash List Node{key,data,next})
struct TN{char D;int SE;struct TN *C[26];};//????(Trie Node{data,string end,child})
struct TSTN{char D;int SE;struct TSTN *L;struct TSTN *E;struct TSTN *R;};//3????(Ternary Search Tree Node{data,string end,left,equal,right})

//?????
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

//MM??
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

//?????
int igcd(int a,int b){int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
long int lgcd(long int a,long int b){long int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
long long int llgcd(long long int a,long long int b){long long int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}
int ilcm(int a,int b){return a*b/igcd(a,b);}
long int llcm(long int a,long int b){return a*b/lgcd(a,b);}
long long int lllcm(long long int a,long long int b){return a*b/llgcd(a,b);}

//????(qsort?4??)
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

//?????
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

//?????
struct SLN **newsln(void){return (struct SLN**) malloc(sizeof(struct SLN*));}
void iisl(struct SLN **h,int d,int p){int k=1;struct SLN *a,*b,*n;n=(struct SLN*) malloc(sizeof(struct SLN));if(!n) return;n->D=d;a=*h;if(p==1){n->N=a;*h=n;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}b->N=n;n->N=a;}}//???????????(Insert In Single List(head,data,position){k,a,b,newnode})
void dfsl(struct SLN **h,int p){int k=1;struct SLN *a,*b;if(*h==NULL) return;a=*h;if(p==1){*h=(*h)->N;free(a);return;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}if(a==NULL) return;else{b->N=a->N;free(a);}}}//???????????(Delete From Single List(head,position){k,a,b})
int sll(struct SLN *h){struct SLN *cu=h;int c=0;while(cu!=NULL){c++;cu=cu->N;}return c;}//????????(Single List Length(head){current,count})

//?????
struct GM *newgm(int v){struct GM *G=(struct GM*) malloc(sizeof(struct GM));int i,j;G->V=v;G->A=imalloc2(G->V);for(i=0;i<G->V;i++){G->A[i]=imalloc(G->V);for(j=0;j<G->V;j++){G->A[i][j]=0;}}return G;}//??????(Make Graph Matrix(vertice){G,i,j})

/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

//????

//main??
int main(void){
    int a[2],b[2],t,v;
    int n;
    int x,y;
    int i;
    scanf("%d%d%d%d%d%d",&a[0],&a[1],&b[0],&b[1],&t,&v);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if((sqrt((x-a[0])*(x-a[0])+(y-a[1])*(y-a[1]))+sqrt((b[0]-x)*(b[0]-x)+(b[1]-y)*(b[1]-y)))/v<=t){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:118:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&a[0],&a[1],&b[0],&b[1],&t,&v);
     ^
./Main.c:119:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:121:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^