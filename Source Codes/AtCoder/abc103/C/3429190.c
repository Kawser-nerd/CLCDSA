#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, sum = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        sum += a - 1;
    }
    printf("%d", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a);
         ^