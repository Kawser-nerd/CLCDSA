#include<stdio.h>
#include<string.h>
int main()
{
    char s[310];
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    char ans[300][300];
    char a[300];
    int i, j;
    int q = 0;
    int x;
    int n = strlen(s);
    for (i = 0; i <= n - k; i++)
    {
        for (j = 0; j < k; j++)
            a[j] = s[j + i];
       a[i + k] = '\0';
        x = 0;
        for (j = 0; j < q; j++)
        {
            if (strcmp(a, ans[j])==0)
            {
                x++;
                break;
            }
        }
        if (x == 0)
        {
            strcpy(ans[q], a);
            q++;
        }
    }
    printf("%d\n", q);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^