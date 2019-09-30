#include<stdio.h>
int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    int i, j;
    int p[11];
    for (i = 0; i < n; i++)
        p[i] = i + 1;
    int x;
    char c[500];
    for (i = 0; i < 2 * n*l; i++)
        scanf("%c", &c[i]);
    for (i = 0; i < 2 * n*l; i++)
    {
        if (c[i] == '-')
        {
            j = i % (2 * n);
            j /= 2;
            j--;
            x = p[j];
            p[j] = p[j + 1];
            p[j + 1] = x;
        }
    }
    char cc[100];
    for (i = 0; i < 2 * n; i++)
        scanf("%c", &cc[i]);
    for (i = 0; i < 2 * n; i++)
    {
        if (cc[i] == 'o')
        {
            j = i / 2;
            printf("%d\n", p[j]);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &l);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c", &c[i]);
         ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c", &cc[i]);
         ^