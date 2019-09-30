#include <stdio.h>
#define NUMBER_OF_SUBJECT 3

int main() {
  int max, rate, score = 0, subject_i;
  for(subject_i = 0; subject_i < NUMBER_OF_SUBJECT; subject_i++) {
    scanf("%d %d", &max, &rate);
    score += max * rate / 10;
  }
  printf("%d\n", score);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &max, &rate);
     ^