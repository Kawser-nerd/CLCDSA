#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  if (n == 3 || n == 5 || n == 7) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^