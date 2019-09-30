#include<stdio.h>

void run(void){
  int n;
  scanf("%d",&n);
  int max=0;
  int maxIndex=1;
  int i,d;
  for(i=2;i<=n;i++){
    printf("? 1 %d\n",i);
    fflush(stdout);
    scanf("%d",&d);
    if(d>max){
      max=d;
      maxIndex=i;
    }
  }
  for(i=1;i<=n;i++){
    if(i==maxIndex) continue;
    printf("? %d %d\n",maxIndex,i);
    fflush(stdout);
    scanf("%d",&d);
    if(d>max) max=d;
  }
  printf("! %d\n",max);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d);
     ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d);
     ^