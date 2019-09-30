#include <stdio.h>

int
main(int argc, char *argv[])
{
  int N;
  scanf("%d", &N);
  
  for(int i = 0; i < 10; i++){
    int a = 111 * (i - 1);
    int b = 111 * i;
    if(a < N && N <= b){
      printf("%d\n", b);
      break;
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^