#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char name[55], kit[55];
    scanf("%s%s", name, kit);
    int nc[30], kc[30];
    int i;
    for (i = 0; i < 30; i++)
        nc[i] = kc[i] = 0;
    for (i = 0; i < n; i++)
        nc[name[i] - 'A']++;
    for (i = 0; i < m; i++)
        kc[kit[i] - 'A']++;
    int max = 0;
    for (i = 0; i < 30; i++)
    {
        if (nc[i] != 0)
        {
            if (kc[i] == 0)
            {
                printf("-1\n");
                return 0;
            }
            if ((nc[i] + kc[i] - 1) / kc[i] > max)
                max = (nc[i] + kc[i] - 1) / kc[i];
        }
    }
    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s", name, kit);
     ^