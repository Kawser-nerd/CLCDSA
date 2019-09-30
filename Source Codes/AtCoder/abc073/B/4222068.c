#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);
  long ans = 0;
  long r,l;

  for(int i = 0;i < N;i++){
    scanf("%ld%ld",&r,&l);
    ans += l-r+1;
  }
  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&r,&l);
     ^