#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
  int x,y,z;
}point;

int compare(const void *a,const void *b){
  return (*(point*)a).z > (*(point*)b).z;
}

int compare_int(const void *a,const void *b){
  if((*(point*)a).x == (*(point*)b).x){
    return (*(point*)a).y > (*(point*)b).y;
  }
  return (*(point*)a).x > (*(point*)b).x;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  point arr[M];
  for(int i = 0;i < M;i++){
    scanf("%d %d",&arr[i].x,&arr[i].y);
    arr[i].z = i;
  }

  qsort(arr,M,sizeof(point),compare_int);

  int p = arr[0].x;
  int cnt = 0;
  for(int i = 0;i < M;i++){
    if(arr[i].x != p){
      p = arr[i].x;
      cnt = 0;
    }
    arr[i].y = ++cnt;
  }

  qsort(arr,M,sizeof(point),compare);

  for(int i = 0;i < M;i++){
    printf("%06d%06d\n",arr[i].x,arr[i].y);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&arr[i].x,&arr[i].y);
     ^