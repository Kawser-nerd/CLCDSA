#include <stdio.h>

int main(void)
{
    int N;
    
    scanf("%d%*c", &N);
    printf("%02d:%02d:%02d\n", N /3600, N % 3600 / 60, N % 3600 % 60);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &N);
     ^