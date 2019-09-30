#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[100005];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int count[100005];
    for (i = 0; i < 100005; i++)
        count[i] = 0;
    int l, r;
    int ans = 1;
    l = 0;
    r = 0;
    count[a[l]] = 1;
    while (r < n - 1)
    {
        if (count[a[r + 1]] == 0)
        {
            r++;
            count[a[r]] = 1;
        }
        else if (l < r)
        {
            count[a[l]] = 0;
            l++;
        }
        else
        {
            count[a[l]] = 0;
            l++;
            r++;
            count[a[l]] = 1;
        }
        if (r - l + 1 > ans)
            ans = r - l + 1;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^