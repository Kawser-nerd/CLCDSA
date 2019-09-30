#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    int can_1 = abs(a - b);
    int can_2 = 10 - can_1;
    printf("%d\n", min(can_1, can_2));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^