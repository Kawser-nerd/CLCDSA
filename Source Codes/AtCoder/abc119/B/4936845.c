#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d",&N);
    
    double price;
    char unit[3];
    
    int i;
    double sum=0;
    
    for (i=0;i<N;i++) {
        scanf("%lf%s",&price,unit);
        if (strcmp("BTC",unit) == 0)
            price = 380000*price;
        sum += price;
    }
    
    printf("%lf\n",sum);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%s",&price,unit);
         ^