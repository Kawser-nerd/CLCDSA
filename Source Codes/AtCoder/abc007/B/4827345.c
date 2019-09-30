#include <stdio.h>

int main() {
  char target_str[12];
  scanf("%s", target_str);
  if(strcmp(target_str, "a") == 0) {
    printf("-1\n");
  } else {
    printf("a\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:6: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
   if(strcmp(target_str, "a") == 0) {
      ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", target_str);
   ^