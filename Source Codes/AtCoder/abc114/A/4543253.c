#include <stdio.h>
#include <string.h>
int main() {
  int input;
  scanf("%d",&input);
  if (input == 3 || input == 5 || input == 7) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&input);
   ^