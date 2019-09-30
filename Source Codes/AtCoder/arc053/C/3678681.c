#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct point{
  int a,b;
} node;

int cmpA(const void *a,const void *b){
  return ((node *)a)->a-((node *)b)->a;
}

int cmpB(const void *a,const void *b){
  return ((node *)b)->b-((node *)a)->b;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *arrayM=(node *)calloc(n,sizeof(node));
  node *arrayP=(node *)calloc(n,sizeof(node));
  int lenM=0;
  int lenP=0;
  int i;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a-b<0){
      arrayM[lenM++]=(node){a,b};
    } else {
      arrayP[lenP++]=(node){a,b};
    }
  }
  qsort(arrayM,lenM,sizeof(node),cmpA);
  qsort(arrayP,lenP,sizeof(node),cmpB);
  int64 now=0;
  int64 max=0;
  for(i=0;i<lenM;i++){
    now+=arrayM[i].a;
    if(now>max) max=now;
    now-=arrayM[i].b;
  }
  for(i=0;i<lenP;i++){
    now+=arrayP[i].a;
    if(now>max) max=now;
    now-=arrayP[i].b;
  }
  printf("%lld\n",max);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^