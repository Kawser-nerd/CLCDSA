#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int b[25];
    int i;
    for (i = 2; i <= n; i++)
        scanf("%d", &b[i]);
    int x;
    int max, min;
    int v[25];
    int j;
    for (i = n; i > 0; i--)
    {
        x = 0;
        max = 0;
        min = 2000000000;
        for (j = i + 1; j <= n; j++)
        {
            if (b[j] == i)
            {
                if (max < v[j])
                    max = v[j];
                if (min > v[j])
                    min = v[j];
                x++;
            }
        }
        if (x == 0)
            v[i] = 1;
        else
            v[i] = max + min + 1;
    }
    printf("%d\n", v[1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &b[i]);
         ^