#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), asc);
    int ans = 0;
    int x = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            x++;
        else
        {
            if (x % 2 == 1)
                ans++;
            x = 1;
        }
    }
    if (x % 2 == 1)
        ans++;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^