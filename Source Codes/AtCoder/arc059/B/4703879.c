#include<stdio.h>
#include<string.h>
int main()
{
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    int i;
    for(i=0;i<n-1;i++)
        if (s[i] == s[i + 1])
        {
            printf("%d %d\n", i + 1, i + 2);
            return 0;
        }
    for(i=0;i<n-2;i++)
        if (s[i] == s[i + 2])
        {
            printf("%d %d\n", i + 1, i + 3);
            return 0;
        }
    printf("-1 -1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^