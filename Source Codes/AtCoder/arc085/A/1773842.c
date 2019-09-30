#include <stdio.h>

int main() {
   int n, m; scanf("%d%d", &n, &m);
   int rs = (100 * (18 * m + n)) << m;
   printf("%d\n", rs);
} ./Main.c: In function ‘main’:
./Main.c:4:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    int n, m; scanf("%d%d", &n, &m);
              ^