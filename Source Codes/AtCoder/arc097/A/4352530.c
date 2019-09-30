#include<stdio.h>
#include<string.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    char s[5003];
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    char a[25005][10];
    int i, j, x, y;
    y = 0;
    int n = strlen(s);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < min(n, i + 5); j++)
        {
            for (x = i; x <= j; x++)
                a[y][x - i] = s[x];
            a[y][x - i] = '\0';
            y++;
        }
    }
    char b[10];
    while (k > 0)
    {
        i = 0;
        while (a[i][0] == '\0')
            i++;
        strcpy(b, a[i]);
        for (; i < y; i++)
        {
            if (strcmp(b, a[i]) > 0 && a[i][0] != '\0')
                strcpy(b, a[i]);
        }
        for (i = 0; i < y; i++)
            if (strcmp(b, a[i]) == 0)
                a[i][0] = '\0';
        k--;
    }
    printf("%s\n", b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^