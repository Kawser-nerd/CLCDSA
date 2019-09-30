#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  int card[] = {1, 2, 3, 4, 5, 6};
  int mod30 = N % 30;
  for(int i = 0; i < mod30; i++) {
    int left = (i % 5);
    int right = left + 1;
    int tmp = card[left];
    card[left]  = card[right];
    card[right] = tmp;
  }

  for(int i = 0; i < 6; i++) {
    printf("%d", card[i]);
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^