#include <stdio.h>

int main() {
  int number_of_items, x, i, flag_items, sum = 0;
  scanf("%d %d", &number_of_items, &x);
  int price[number_of_items + 1];
  for(i = 0; i < number_of_items; i++) {
    scanf("%d", &price[i]);
    flag_items = x & 1;
    x /= 2;
    if(flag_items == 1) {
      sum += price[i];
    }
  }
  printf("%d\n", sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &number_of_items, &x);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &price[i]);
     ^