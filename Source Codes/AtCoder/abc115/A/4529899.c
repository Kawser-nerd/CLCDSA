#include <stdio.h>
#include <string.h>
int main() {
  int D;
  scanf("%d",&D);
  if (D == 25) {
    printf("Christmas\n");
  } else if (D == 24) {
    printf("Christmas Eve\n");
  } else if (D == 23) {
    printf("Christmas Eve Eve\n");
  } else if (D == 22) {
    printf("Christmas Eve Eve Eve\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&D);
   ^