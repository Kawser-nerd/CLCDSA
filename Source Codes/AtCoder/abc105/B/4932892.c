#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
  int N;
  scanf("%d", &N);
  if (N == 1) {
    printf("No");
  }
  else if (N == 2) {
    printf("No");
  }
  else if (N == 3) {
    printf("No");
  }
  else if (N == 5) {
    printf("No");
  }
  else if (N == 6) {
    printf("No");
  }
  else if (N == 9) {
    printf("No");
  }
  else if (N == 10) {
    printf("No");
  }
  else if (N == 13) {
    printf("No");
  }
  else if (N == 17) {
    printf("No");
  }
  else {
    printf("Yes");
  }
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^