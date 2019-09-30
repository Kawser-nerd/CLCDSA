#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    char w[50][101];
    int i, ans = 0;
    for (i = 0; i < n; i++)
        scanf("%s", w[i]);
    for (i = 0; i < n - 1; i++)
    {
        if ((w[i][0] == 'T') && (w[i][1] == 'A') && (w[i][2] == 'K') && (w[i][3] == 'A')
            && (w[i][4] == 'H') && (w[i][5] == 'A') && (w[i][6] == 'S') && (w[i][7] == 'H') && (w[i][8] == 'I')
            && (w[i][9] == 'K') && (w[i][10] == 'U') && (w[i][11] == 'N') && (w[i][12] == '\0'))
        {
            ans++;
            continue;
        }
        if ((w[i][0] == 'T') || (w[i][0] == 't'))
        {
            if ((w[i][1] == 'a') && (w[i][2] == 'k') && (w[i][3] == 'a')
                && (w[i][4] == 'h') && (w[i][5] == 'a') && (w[i][6] == 's') && (w[i][7] == 'h') && (w[i][8] == 'i')
                && (w[i][9] == 'k') && (w[i][10] == 'u') && (w[i][11] == 'n') && (w[i][12] == '\0'))
            {
                ans++;
                continue;
            }
        }
    }
    i = n - 1;
    if ((w[i][0] == 'T') && (w[i][1] == 'A') && (w[i][2] == 'K') && (w[i][3] == 'A')
        && (w[i][4] == 'H') && (w[i][5] == 'A') && (w[i][6] == 'S') && (w[i][7] == 'H') && (w[i][8] == 'I')
        && (w[i][9] == 'K') && (w[i][10] == 'U') && (w[i][11] == 'N') && (w[i][12] == '.')&&(w[i][13]=='\0'))
        ans++;
    if ((w[i][0] == 'T') || (w[i][0] == 't'))
    {
        if ((w[i][1] == 'a') && (w[i][2] == 'k') && (w[i][3] == 'a')
            && (w[i][4] == 'h') && (w[i][5] == 'a') && (w[i][6] == 's') && (w[i][7] == 'h') && (w[i][8] == 'i')
            && (w[i][9] == 'k') && (w[i][10] == 'u') && (w[i][11] == 'n') && (w[i][12] == '.') && (w[i][13] == '\0'))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", w[i]);
         ^