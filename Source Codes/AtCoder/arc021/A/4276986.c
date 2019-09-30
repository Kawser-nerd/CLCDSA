#include<stdio.h>
int main()
{
    int i, j;
    int a[5][5];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                printf("CONTINUE\n");
                return 0;
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == a[i + 1][j])
            {
                printf("CONTINUE\n");
                return 0;
            }
        }
    }
    printf("GAMEOVER\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &a[i][j]);
             ^