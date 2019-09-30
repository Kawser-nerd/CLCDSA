#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct indexedval{
  int v;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return p->v-q->v;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *a=(node *)malloc(sizeof(node)*n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i].v);
    a[i].index=i+1;
  }
  qsort(a,n,sizeof(node),cmp);
  for(i=n-1;i>=0;i--){
    printf("%d\n",a[i].index);
  }
  free(a);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i].v);
     ^