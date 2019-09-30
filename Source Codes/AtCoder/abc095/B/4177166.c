#include <stdio.h>

int main(void){
  int N,m,min = 1001;
  long X,ans = 0;
  scanf("%d%ld",&N,&X);

  for(int i = 0;i < N;i++){
    scanf("%d",&m);
    if(min > m) min = m;
    X -= m;
  }
  ans = N;
  ans += X/min;

  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%ld",&N,&X);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^