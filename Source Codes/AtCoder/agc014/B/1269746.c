#include <stdio.h>

#define MAXN 200000
int a[MAXN];

int main(void)
{
    int n, m;
    scanf("%i %i", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%i %i", &u, &v);
        a[u]++;
        a[v]++;
    }

    for (int i = 1; i <= m; i++)
    {
        if (a[i] % 2)
        {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%i %i", &n, &m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%i %i", &u, &v);
         ^