#include<stdio.h>

#define ABS(x) (((x)<0)?(-(x)):(x))
#define MAX(x,y) (((x)>(y))?(x):(y))

int main(void){
  int N,Z,W,an,anm;
  int i,j,k;
  scanf("%d%d%d",&N,&Z,&W);
  if(N!=1){
    for(i=0;i<N-2;i++) scanf("%*d");
    scanf("%d%d",&anm,&an);
  }else{
    scanf("%d",&an);
    anm=W;
  }
  printf("%d\n",MAX(ABS(an-anm),ABS(W-an)));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&N,&Z,&W);
   ^
./Main.c:11:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<N-2;i++) scanf("%*d");
                        ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&anm,&an);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&an);
     ^