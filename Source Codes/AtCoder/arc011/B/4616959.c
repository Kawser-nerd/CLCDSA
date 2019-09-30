#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, j;
    char s[50];
    int x = 0, y;
    int m;
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        y = 0;
        for (j = 0; j < strlen(s); j++)
        {
            m = -10;
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] += 'a' - 'A';
            if (s[j] == 'b' || s[j] == 'c')m = 1;
            if (s[j] == 'd' || s[j] == 'w')m = 2;
            if (s[j] == 't' || s[j] == 'j')m = 3;
            if (s[j] == 'f' || s[j] == 'q')m = 4;
            if (s[j] == 'l' || s[j] == 'v')m = 5;
            if (s[j] == 's' || s[j] == 'x')m = 6;
            if (s[j] == 'p' || s[j] == 'm')m = 7;
            if (s[j] == 'h' || s[j] == 'k')m = 8;
            if (s[j] == 'n' || s[j] == 'g')m = 9;
            if (s[j] == 'z' || s[j] == 'r')m = 0;
            if (m >= 0)
            {
                if (x == 1 && y == 0)
                    printf(" ");
                printf("%d", m);
                y++;
            }
            if (j == strlen(s) - 1)
            {
                if (y == 0 && x == 0)
                    x = 0;
                else
                    x = 1;
            }
        }
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s);
         ^