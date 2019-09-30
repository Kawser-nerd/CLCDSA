#include<stdio.h>
int main(void){
    long x,count;
    scanf("%ld",&x);

        count = (x-x%11)/11;
        count *= 2;
        if(x%11 != 0)count++;
        if(x%11 > 6)count++;

    printf("%ld",count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&x);
     ^