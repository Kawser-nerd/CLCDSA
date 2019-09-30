#include <stdio.h>

int main(void) 
{
    int ab, bc, ca;
    scanf("%d %d %d", &ab, &bc, &ca);
    printf("%d\n", ab*bc/2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &ab, &bc, &ca);
     ^