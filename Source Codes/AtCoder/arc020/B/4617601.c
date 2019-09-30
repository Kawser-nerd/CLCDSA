#include<stdio.h>
int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    int i;
    int a[102];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int c1, c2;
    int min = 100000000, cost;
    for (c1 = 1; c1 <= 10; c1++)
    {
        for (c2 = 1; c2 <= 10; c2++)
        {
            if (c1 != c2)
            {
                cost = 0;
                for (i = 0; i < n; i++)
                {
                    if (i % 2 == 0)
                    {
                        if (a[i] != c1)
                            cost += c;
                    }
                    else
                    {
                        if (a[i] != c2)
                            cost += c;
                    }
                }
                if (min > cost)
                    min = cost;
            }
        }
    }
    printf("%d\n", min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &c);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^