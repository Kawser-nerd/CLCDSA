#include<stdio.h>
#include<math.h>
int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    int i;
    int a[55];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int o, e;
    o = e = 0;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            e++;
        else
            o++;
    if (o == 0)
    {
        if (p == 1)
            printf("0\n");
        else
            printf("%.0lf\n", pow(2, e));
    }
    else
    {
        printf("%.0lf\n", pow(2, e + o - 1));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &p);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^