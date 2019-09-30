#include <stdio.h>
#include <string.h>

int main() {
  char str_a[51], str_b[51];
  size_t length_str_a, length_str_b;
  scanf("%s", str_a);
  scanf("%s", str_b);
  length_str_a = strlen(str_a);
  length_str_b = strlen(str_b);
  if(length_str_a > length_str_b) {
    printf("%s\n", str_a);
  } else {
    printf("%s\n", str_b);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str_a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str_b);
   ^