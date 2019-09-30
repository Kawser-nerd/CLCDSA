#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
        long long int X;
        long long int t;
        scanf("%lld %lld", &X,&t);
        if (t>=X) {
                printf("0\n");
                return 0;
        }else{
                printf("%lld\n",X-t);
        }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld", &X,&t);
         ^