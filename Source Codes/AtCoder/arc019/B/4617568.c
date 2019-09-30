#include<stdio.h>
#include<string.h>
int main()
{
    char a[300005];
    scanf("%s", a);
    int i;
    int l = strlen(a);
    if (l == 1)
    {
        printf("0\n");
        return 0;
    }
    int x = 0;
    for (i = 0;; i++)
    {
        if (i >= l - i - 1)
            break;
        if (a[i] != a[l - i - 1])
            x++;
    }
    if (x > 1)
        printf("%d\n", 25 * l);
    if (x == 1)
        printf("%d\n", 25 * (l - 2) + 24 * 2);
    if (x == 0)
    {
        if (l % 2 == 0)
            printf("%d\n", 25 * l);
        else
            printf("%d\n", 25 * (l - 1));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a);
     ^