#include<stdio.h>
#include<string.h>
int m[108][108];
int a[10008];
int main()
{
    int H, W, N, i, j;
    scanf("%d%d", &H, &W);
    scanf("%d", &N);
    int sum = 0;
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    i = 1;
    int x = 0, y = 1;
    int k = 1;
    j = 1;
    while(i <= sum)
    {
        while(!m[x + 1][y] && x + 1 <= H)
        {
            x++;
            i++;
            if(a[j] > 0)
            {
                k = j;
                a[j]--;
            }
            else
            {
                k = ++j;
                a[j]--;
            }
            m[x][y] = k;
        }
        while(!m[x][y + 1] && y + 1 <= W)
        {
            y++;
            i++;
            if(a[j] > 0)
            {
                k = j;
                a[j]--;
            }
            else
            {
                k = ++j;
                a[j]--;
            }
            m[x][y] = k;
        }
        while(!m[x - 1][y] && x - 1 > 0)
        {
            x--;
            i++;
            if(a[j] > 0)
            {
                k = j;
                a[j]--;
            }
            else
            {
                k = ++j;
                a[j]--;
            }
            m[x][y] = k;
        }
        while(!m[x][y - 1] && y - 1 > 0)
        {
            y--;
            i++;
            if(a[j] > 0)
            {
                k = j;
                a[j]--;
            }
            else
            {
                k = ++j;
                a[j]--;
            }
            m[x][y] = k;
        }
    }
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            printf(j == 1 ? "%d" : " %d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &H, &W);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^