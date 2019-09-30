#include <stdio.h>

int main(void)
{
    int i;
    scanf("%d",&i);

    if(1<=i&&i<=999){
        printf("ABC\n");
    }else if(1000<=i&&i<=1998){
        printf("ABD\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&i);
     ^