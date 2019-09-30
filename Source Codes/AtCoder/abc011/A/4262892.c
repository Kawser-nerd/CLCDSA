#include <stdio.h>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    
    int nextMonth;
    if(n == 12)
    {
        nextMonth = 1;
    }
    else
    {
        nextMonth = n + 1;
    }

    printf("%d\n", nextMonth);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^