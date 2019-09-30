#include<stdio.h>
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int i, j;
    int l, r, t;
    int a[102] = {};
    for (i = 0; i < q; i++)
    {
        scanf("%d %d %d", &l, &r, &t);
        l--;
        for (j = l; j < r; j++)
            a[j] = t;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &q);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &l, &r, &t);
         ^