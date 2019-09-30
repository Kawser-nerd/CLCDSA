#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int d[500];
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", &d[i]);
    int max;
    max = 0;
    for (i = 0; i < n; i++)
        max += d[i];
    int min;
    int sum;
    int m;
    m = sum = 0;
    for (i = 0; i < n; i++)
    {
        if (m < d[i])
        {
            sum += m;
            m = d[i];
        }
        else
            sum += d[i];
    }
    if (sum > m)
        min = 0;
    else
        min = m - sum;
    printf("%d\n%d\n", max, min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &d[i]);
         ^