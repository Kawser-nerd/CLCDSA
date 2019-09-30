#include <stdio.h>

int
main(int argc,char *argv[])
{
  int n; int h[110] = {};
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &h[i]);
  }
  
  int l = 0;
  
  for(int i = 0; i < 100; i++){
    for(int j = 0; j <= n ; j++){
      if(h[j] <= 0 && h[j + 1] > 0){
        l++;
      }
      h[j] -= 1;
    }
  }
  
  printf("%d\n", l);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &h[i]);
     ^