#include <stdio.h>
int main(void) {
  int n, s = 0, min = 10000;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    if(k < min && k % 10 != 0) min = k;
    s += k;
  }
  if(s % 10 == 0 && min == 10000) puts("0");
  else if(s % 10 == 0 && min != 10000) printf("%d\n", s - min);
  else printf("%d\n", s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^