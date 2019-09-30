#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define ASSIGN(a,b) do{\
    vertex[len]=a;\
    next[len]=start[b];\
    start[b]=len;\
    len++;\
} while(0)

typedef struct heapnode{
  int v;
  int min;
} node;

node *heap=NULL;
int heapSize=0;

int cmp(node *a,node *b){
  return a->min>=b->min;
}

void swap(node *a,node *b){
  node t=*a;
  *a=*b;
  *b=t;
  return;
}

void push(int v,int min){
  heapSize++;
  heap[heapSize].v=v;
  heap[heapSize].min=min;
  int k=heapSize;
  while(k>1){
    if(cmp(heap+k/2,heap+k)) break;
    swap(heap+k/2,heap+k);
    k/=2;
  }
  return;
}

void pop(int *v,int *min){
  *v=heap[1].v;
  *min=heap[1].min;
  heap[1]=heap[heapSize--];
  int k=1;
  while(2*k+1<=heapSize){
    int next=cmp(heap+2*k,heap+2*k+1)?2*k:2*k+1;
    if(cmp(heap+k,heap+next)) break;
    swap(heap+k,heap+next);
    k=next;
  }
  if(2*k<=heapSize && cmp(heap+2*k,heap+k)) swap(heap+2*k,heap+k);
  return;
}

void run(void){
  int n,m,s;
  scanf("%d%d%d",&n,&m,&s);
  int *vertex=(int *)malloc(sizeof(int)*2*m);
  int *next=(int *)malloc(sizeof(int)*2*m);
  int *start=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) start[i]=-1;
  int len=0;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    ASSIGN(a,b);
    ASSIGN(b,a);
  }
  heap=(node *)malloc(sizeof(node)*m);
  heapSize=0;
  int *dp=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++) dp[i]=0;
  push(s,s);
  while(heapSize>0){
    int v,min;
    pop(&v,&min);
    min=MIN(min,v);
    if(min<=dp[v]) continue;
    dp[v]=min;
    int p;
    for(p=start[v];p!=-1;p=next[p]){
      int u=vertex[p];
      if(min<=dp[u]) continue;
      push(u,min);
    }
  }
  for(i=1;i<=n;i++){
    if(dp[i]==i){
      printf("%d\n",i);
    }
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:67:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&s);
   ^
./Main.c:76:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^