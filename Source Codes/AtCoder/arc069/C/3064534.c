#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct indexode{
  int a;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  if(p->a!=q->a) return p->a-q->a;
  return p->index-q->index;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *a=(node *)malloc(sizeof(node)*(n+1));
  int i;
  for(i=1;i<=n;i++){
    int b;
    scanf("%d",&b);
    a[i].a=b;
    a[i].index=i;
  }
  a[0].a=0;
  a[0].index=0;
  qsort(a,n+1,sizeof(node),cmp);
  int64 *ans=(int64 *)calloc(n+1,sizeof(int64));
  int min=n;
  for(i=n;i>0;i--){
    int j=i;
    while(j>0 && a[j].a==a[i].a) j--;
    min=MIN(min,a[j+1].index);
    ans[min]+=(int64)(a[i].a-a[j].a)*(n-j);
    i=j+1;
  }
  for(i=1;i<=n;i++){
    printf("%lld\n",ans[i]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^