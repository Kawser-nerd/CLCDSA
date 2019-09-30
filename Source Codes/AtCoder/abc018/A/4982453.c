#include <stdio.h>

int main() {
  int score_a, score_b, score_c;
  scanf("%d", &score_a);
  scanf("%d", &score_b);
  scanf("%d", &score_c);
  if(score_a > score_b && score_a > score_c) {
    printf("1\n");
    if(score_b > score_c) {
      printf("2\n3\n");
    } else {
      printf("3\n2\n");
    }
  } else if(score_b > score_a && score_c > score_a) {
    printf("3\n");
    if(score_b > score_c) {
      printf("1\n2\n");
    } else {
      printf("2\n1\n");
    }
  } else {
    printf("2\n");
    if(score_b > score_c) {
      printf("1\n3\n");
    } else {
      printf("3\n1\n");
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &score_a);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &score_b);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &score_c);
   ^