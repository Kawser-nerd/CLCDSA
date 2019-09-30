/***************************************************************************************************************************************************/
//??????????
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

//??(??)
#define MAX(a,b) ((a)>(b)?(a):(b))//???????
#define MIN(a,b) ((a)<(b)?(a):(b))//???????
#define GCD(a,b) (gcd(a,b))//?????
#define LCM(a,b) ((a)*(b)/gcd((a),(b)))//?????
#define MALLOC(a,n) a=malloc(sizeof(int)*(n))//?????(int)
#define MALLOC2(a,n) a=malloc(sizeof(int*)*(n))//?????(int*)
#define LMALLOC(a,n) a=malloc(sizeof(long int)*(n))//?????(long int)
#define LMALLOC2(a,n) a=malloc(sizeof(long int*)*(n))//?????(long int*)
#define LLMALLOC(a,n) a=malloc(sizeof(long long int)*(n))//?????(long long int)
#define LLMALLOC2(a,n) a=malloc(sizeof(long long int*)*(n))//?????(long long int*)
#define DMALLOC(a,n) a=malloc(sizeof(double)*(n))//?????(double)
#define DMALLOC2(a,n) a=malloc(sizeof(double*)*(n))//?????(double*)
#define CMALLOC(a,n) a=malloc(sizeof(char)*(n))//?????(char)
#define CMALLOC2(a,n) a=malloc(sizeof(char*)*(n))//?????(char*)

//??(???)
#define SORTU(a,n) qsort(a,n,sizeof(int),cmpu)//?????(int)
#define LSORTU(a,n) qsort(a,n,sizeof(long int),lcmpu)//?????(long int)
#define LLSORTU(a,n) qsort(a,n,sizeof(long long int),llcmpu)//?????(long long int)
#define DSORTU(a,n) qsort(a,n,sizeof(double),dcmpu)//?????(double)
#define CSORTU(a,n) qsort(a,n,sizeof(char),ccmpu)//?????(char)
#define SSORTU(a,n) qsort(a,n,sizeof(a[0]),scmpu)//?????(string)
#define SORTD(a,n) qsort(a,n,sizeof(int),cmpd)//?????(int)
#define LSORTD(a,n) qsort(a,n,sizeof(long int),lcmpd)//?????(long int)
#define LLSORTD(a,n) qsort(a,n,sizeof(long long int),llcmpd)//?????(long long int)
#define DSORTD(a,n) qsort(a,n,sizeof(double),dcmpd)//?????(double)
#define CSORTD(a,n) qsort(a,n,sizeof(char),ccmpd)//?????(char)
#define SSORTD(a,n) qsort(a,n,sizeof(a[0]),scmpd)//?????(string)

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

//GCD??
int gcd(int a,int b){int r,t;if(a<b){t=a;a=b;b=t;}r=a%b;while(r!=0){a=b;b=r;r=a%b;}return b;}

//????(qsort?4??)
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

//?????
struct SLN *newsln(int d){struct SLN *L=(struct SLN*) malloc(sizeof(struct SLN));L->D=d;L->N=NULL;return L;}
void iisl(struct SLN **h,int d,int p){int k=1;struct SLN *a,*b,*n;n=(struct SLN*) malloc(sizeof(struct SLN));if(!n) return;n->D=d;a=*h;if(p==1){n->N=a;*h=n;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}b->N=n;n->N=a;}}//???????????(Insert In Single List(head,data,position){k,a,b,newnode})
void dfsl(struct SLN **h,int p){int k=1;struct SLN *a,*b;if(*h==NULL) return;a=*h;if(p==1){*h=(*h)->N;free(a);return;}else{while((a!=NULL) && (k<p)){k++;b=a;a=a->N;}if(a==NULL) return;else{b->N=a->N;free(a);}}}//???????????(Delete From Single List(head,position){k,a,b})
int sll(struct SLN *h){struct SLN *cu=h;int c=0;while(cu!=NULL){c++;cu=cu->N;}return c;}//????????(Single List Length(head){current,count})

//?????
struct GM *newgm(int v){struct GM *G=(struct GM*) malloc(sizeof(struct GM));int i,j;G->V=v;MALLOC2(G->A,G->V);for(i=0;i<G->V;i++){MALLOC(G->A[i],G->V);for(j=0;j<G->V;j++){G->A[i][j]=0;}}return G;}//??????(Make Graph Matrix(vertice){G,i,j})

/***************************************************************************************************************************************************/
//??????????
/***************************************************************************************************************************************************/

//????


//main??
int main(void){
    int n;
    scanf("%d",&n);
    printf("%d\n",n-1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:103:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^