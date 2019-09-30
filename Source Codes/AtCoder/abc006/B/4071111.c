#include <stdio.h>

int main(void)
{
    int n, ans;
    scanf("%d", &n);

    if (n == 1 || n == 2)
    {
        ans = 0;
    }
    else if (n == 3)
    {
        ans = 1;
    }
    else
    {
        int a = 0;
        int b = 0;
        int c = 1;

        for (int i = 4; i <= n; i++)
        {
            int tmp = (a + b + c) % 10007;
            a = b;
            b = c;
            c = tmp;
        }

        ans = c;
    }

    printf("%d\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^