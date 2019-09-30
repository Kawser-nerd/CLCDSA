#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
  int x,y;
}point;

point data[100000];

int compare_int(const void *b,const void *a){
  return (*(point*)a).y < (*(point*)b).y;
}


int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  for(int i = 0;i < M;i++){
    scanf("%d%d",&data[i].x,&data[i].y);
  }

  qsort(data,M,sizeof(point),compare_int);

  int pos = data[0].y;
  int ans = 1;
  for(int i = 1;i < M;i++){
    if(pos <= data[i].x){
      ans++;
      pos = data[i].y;
    }
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&data[i].x,&data[i].y);
     ^