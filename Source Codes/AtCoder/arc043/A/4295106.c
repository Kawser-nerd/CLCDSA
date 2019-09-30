#include<stdio.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int s[100005];
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    unsigned long long int max, min, sum;
    max = 0;
    min = 2000000000;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += s[i];
        if (max < s[i])
            max = s[i];
        if (min > s[i])
            min = s[i];
    }
    double ave = (double)sum / (double)n;
    if (max == min)
    {
        printf("-1\n");
        return 0;
    }
    double p, q;
    p = (double)b / (double)(max - min);
    q = (double)a - ave * p;
    printf("%.20lf %.20lf\n", p, q);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &s[i]);
         ^