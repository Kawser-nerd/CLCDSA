#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct inode{
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
    int m;
    scanf("%d",&m);
    a[i].v=m;
    a[i].index=i;
  }
  qsort(a,n,sizeof(node),cmp);
  int ans=0;
  for(i=0;i<n;i++) if(i%2!=a[i].index%2) ans++;
  printf("%d\n",ans/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^