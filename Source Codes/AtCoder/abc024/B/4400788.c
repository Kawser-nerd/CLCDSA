#include <stdio.h>

int main(void){
  int N,T;
  scanf("%d%d",&N,&T);

  int a,pa;
  long time = T;
  scanf("%d",&pa);
  for(int i = 1;i < N;i++){
    scanf("%d",&a);
    if(a-pa > T) time += T;
    else time += a-pa;
    pa = a;
  }

  printf("%ld\n",time);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&T);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&pa);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^