#include <stdio.h>
int main() {
int n, a, b;
scanf("%d", &n);
scanf("%d", &a);
scanf("%d", &b);
if(n <= 5) {
printf("%d\n", b * n);
} else {
printf("%d\n", b * 5 + (n - 5) * a);
} return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d", &n);
 ^
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d", &a);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d", &b);
 ^