#include <stdio.h>
#include <string.h>

int main (void){

    int n;
    int sum = 100;
    scanf("%d", &n);

    for(int a = 1; a <= n-1; a++){
        int b = n - a;

        int asum = 0;
        int bsum = 0;

        int tmp = a;
        while( tmp != 0 ){
             asum += tmp%10;
             tmp /= 10;       
        }

        tmp = b;
        while( tmp != 0 ){
             bsum += tmp%10;
             tmp /= 10;
        }

        if( sum > asum + bsum )
          sum = asum + bsum;

    }

    printf("%d", sum);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^