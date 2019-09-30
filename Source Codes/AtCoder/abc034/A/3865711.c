#include<stdio.h>
int main(void)
{
    int x,y;
    scanf("%d ",&x);
    scanf("%d",&y);
    if(y>x){
        printf("Better\n");
        return 0;
    }
    printf("Worse\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&x);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y);
     ^