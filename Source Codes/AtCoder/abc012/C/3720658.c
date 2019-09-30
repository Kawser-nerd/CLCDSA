#include <stdio.h>
#define SUM 2025

int main(void)
{
    int N;
    int i;
    
    scanf("%d%*c", &N);
    for(i = 1; i <= 9; i++){
        if((SUM - N) % i == 0 && (SUM - N) / i <= 9){
            printf("%d x %d\n", i, (SUM - N) / i);
        }
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &N);
     ^