#include <stdio.h>

int main() {
  int number_of_flowers, sum_removing_petals = 0, flower_i, petals;
  scanf("%d", &number_of_flowers);
  for(flower_i = 0; flower_i < number_of_flowers; flower_i++) {
    scanf("%d", &petals);
    while((petals % 3 == 2) || (petals % 2 == 0)) {
      petals--;
      sum_removing_petals++;
    }
  }
  printf("%d\n", sum_removing_petals);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_of_flowers);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &petals);
     ^