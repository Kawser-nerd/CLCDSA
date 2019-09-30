#include <stdio.h>
int main(void){
    int y,tf;
    scanf("%d",&y);
    tf=(y%4==0)+(y%100==0)+(y%400==0);
    printf("%s\n",tf%2?"YES":"NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y);
     ^