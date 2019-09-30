#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("NO\n");
        return 0;
    }
    int i;
    for(i=3;i<=sqrt(n);i+=2)
        if (n%i == 0)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^