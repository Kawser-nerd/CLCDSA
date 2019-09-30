#include <stdio.h>

int
main(int argc, char *argv[])
{
  int a[3];
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  
  int m = 0;
  for(int i = 0; i < 3; i++){
    if(m < a[i]){
      m = a[i];
    }
  }
  
  int ans = 9 * m + a[0] + a[1] + a[2];
  
  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a[0], &a[1], &a[2]);
   ^