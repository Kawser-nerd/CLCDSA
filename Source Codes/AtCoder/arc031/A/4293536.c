#include<stdio.h>
#include<string.h>
int main()
{
    char name[102];
    scanf("%s", name);
    int n = strlen(name);
    int i;
    for (i = 0; i < n / 2; i++)
    {
        if (name[i] != name[n - i - 1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", name);
     ^