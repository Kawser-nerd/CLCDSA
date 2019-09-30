#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    printf("%d\n", op == '+' ? a + b : a - b);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %c %d", &a, &op, &b);
     ^