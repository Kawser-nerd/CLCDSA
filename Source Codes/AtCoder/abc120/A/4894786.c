#include<stdio.h>

int main(void)
{
        int A, B, C, s;

        scanf("%d%d%d", &A, &B, &C);

        s = B / A;
        if(C>s) printf("%d\n", s);

        else printf("%d\n", C);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &A, &B, &C);
         ^