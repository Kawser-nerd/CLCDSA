#include<stdio.h>
int main()
{
    long long int x,y;
    int result;
    scanf("%lld %lld", &x, &y);
    for(result=0; ; result++) {
        if(x > y)
            break;
        else
            x = x * 2;
    }
    printf("%d\n", result);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &x, &y);
     ^