#include <stdio.h>

int main() {
  int N, i;
  int temp[] = {0, 0, 1};
  scanf("%d", &N);
  if(N == 1) {
    printf("0\n");
    return 0;
  }
  if(N == 2) {
    printf("0\n");
    return 0;
  }
  for(i = 0; i < N-4; i++) {
    temp[i%3] = (temp[0] + temp[1] + temp[2]) % 10007;
  }
  printf("%d\n", (temp[0] + temp[1] + temp[2]) % 10007);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^