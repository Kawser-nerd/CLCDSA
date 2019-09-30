#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
        char a,b;
        scanf("%c %c",&a,&b );
        if (a==b) {
                printf("H\n");
        }else{
                printf("D\n");
        }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c %c",&a,&b );
         ^