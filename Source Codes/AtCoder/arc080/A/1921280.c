#include <stdio.h>

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d",&N);
    int number[N];
    for(int i = 0;i < N;i++)
    {
        int x;
        scanf("%d",&x);
        number[i] = x;
    }
    int n4 = 0,n2 = 0,n1 = 0;
    for(int i = 0;i < N;i++)
    {
        if(number[i] % 4 == 0)
        {
            n4 = n4 + 1;
        }
        else if((number[i] % 2 == 0) && (number[i] % 4 != 0))
        {
            n2 = n2 + 1;
        }
    }
    n1 = N - n2 - n4;
    if(n1 != 0)
    {
        if(n2 == 0)
        {
            if(n4 >= n1 - 1)
            {
                printf("Yes");
            }
            else
            {
                printf("No");
            }
        }
        else
        {
            if(n4 == n1)
            {
                printf("Yes");
            }
            else
            {
                printf("No");
            }
        }
    }
    else
    {
        if(n4 == 0)
        {
            if(n2 >= 2)
            {
                 printf("Yes");
            }
            else
            {
                 printf("No");
            }
        }
        else
        {
            printf("Yes");
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^