#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct point{
  int a,b;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  int x=MAX(p->a,p->a-p->b+q->a);
  int y=MAX(q->a,q->a-q->b+p->a);
  return x-y;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *arrayP=(node *)calloc(n,sizeof(node));
  node *array0=(node *)calloc(n,sizeof(node));
  node *arrayM=(node *)calloc(n,sizeof(node));
  int lenP=0;
  int lenM=0;
  int len0=0;
  int i;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a-b>0){
      arrayP[lenP++]=(node){a,b};
    } else if(a-b<0){
      arrayM[lenM++]=(node){a,b};
    } else {
      array0[len0++]=(node){a,b};
    }
  }
  qsort(arrayP,lenP,sizeof(node),cmp);
  qsort(arrayM,lenM,sizeof(node),cmp);
  int64 now=0;
  int64 max=0;
  for(i=0;i<lenM;i++){
    now+=arrayM[i].a;
    max=MAX(max,now);
    now-=arrayM[i].b;
  }
  for(i=0;i<len0;i++) max=MAX(max,now+array0[i].a);
  for(i=0;i<lenP;i++){
    now+=arrayP[i].a;
    max=MAX(max,now);
    now-=arrayP[i].b;
  }
  printf("%lld\n",max);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^