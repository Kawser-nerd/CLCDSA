#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*W+(j))

void run(void){
  int H,W,h,w;
  scanf("%d%d%d%d",&H,&W,&h,&w);
  if(H%h==0 && W%w==0){
    printf("No\n");
    return;
  }
  int *b=(int *)calloc(H*W,sizeof(int));
  const int m=(1000000000-1)/(h*w-1);
  int64 sum=0;
  int i,j;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      b[POS(i,j)]=(i%h==h-1 && j%w==w-1?-m*(h*w-1)-1:m);
      sum+=b[POS(i,j)];
    }
  }
  if(sum<=0){
    printf("No\n");
    return;
  }
  printf("Yes\n");
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      printf("%d ",b[POS(i,j)]);
    }
    printf("\n");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&H,&W,&h,&w);
   ^