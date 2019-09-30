#include <stdio.h>

int
main(int argc, char *argv[])
{
  int N, p[10];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &p[i]);
  }

  int m = 0;
  int sum = 0;

  for(int i = 0; i < N; i++){
    sum += p[i];
    if(m < p[i]){
      m = p[i];
    }
  }

  printf("%d\n", sum - m / 2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &p[i]);
     ^