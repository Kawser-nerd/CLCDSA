#include <stdio.h>

int main(void)
{
    int n, t, min;

    scanf("%d", &n);
    scanf("%d", &min);

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &t);

        if (t < min)
        {
            min = t;
        }
    }

    printf("%d\n", min);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &min);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &t);
         ^