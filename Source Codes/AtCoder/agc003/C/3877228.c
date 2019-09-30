#include<stdio.h>
#include<stdlib.h>

typedef struct indexNode{
  int v;
  int index;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->v-((node *)b)->v;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *a=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int v;
    scanf("%d",&v);
    a[i]=(node){v,i};
  }
  qsort(a,n,sizeof(node),cmp);
  int cnt=0;
  for(i=0;i<n;i++) if(i%2!=a[i].index%2) cnt++;
  printf("%d\n",cnt/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&v);
     ^