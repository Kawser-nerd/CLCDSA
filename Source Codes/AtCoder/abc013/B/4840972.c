#include <stdio.h>

int main() {
  int number_a, number_b, temp, check, answer;
  scanf("%d", &number_a);
  scanf("%d", &number_b);
  if(number_a < number_b) {
    temp = number_a;
    number_a = number_b;
    number_b = temp;
  }
  check = number_a - number_b;
  answer = (check <= 5)? check : 10 - check;
  printf("%d\n", answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_a);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_b);
   ^