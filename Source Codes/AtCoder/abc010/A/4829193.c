#include <stdio.h>

int main() {
  char handle_name[11];
  scanf("%s", handle_name);
  printf("%spp\n", handle_name);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", handle_name);
   ^