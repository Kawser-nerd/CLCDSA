#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, j;
    char w[102][30];
    for (i = 0; i < n; i++)
        scanf("%s", w[i]);
    for (i = 1; i < n; i++)
    {
        if (w[i][0] != w[i - 1][strlen(w[i - 1]) - 1])
        {
            if (i % 2 == 0)
                printf("LOSE\n");
            else
                printf("WIN\n");
            return 0;
        }
        for (j = 0; j < i; j++)
        {
            if (strcmp(w[i], w[j]) == 0)
            {
                if (i % 2 == 0)
                    printf("LOSE\n");
                else
                    printf("WIN\n");
                return 0;
            }
        }
    }
    printf("DRAW\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", w[i]);
         ^