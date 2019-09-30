#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    
    scanf("%d%*c", &a);
    scanf("%d%*c", &b);
    if(abs(a - b) <= 5){
        printf("%d\n", abs(a - b));
    }else{
        printf("%d\n", 10 - abs(a - b));
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &a);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &b);
     ^