#include <stdio.h>

int
main(int argc, char argv[])
{
  int K, ans;
  scanf("%d", &K);
  
  if(K % 2 == 1){
   ans = (K / 2) * (K / 2 + 1);
  }
  else{
   ans = (K / 2) * (K / 2);
  }
  
  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &K);
   ^