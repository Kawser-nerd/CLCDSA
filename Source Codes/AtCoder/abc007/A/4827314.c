#include <stdio.h>

int main() {
  int number_of_tree;
  scanf("%d", &number_of_tree);
  printf("%d\n", number_of_tree - 1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_of_tree);
   ^