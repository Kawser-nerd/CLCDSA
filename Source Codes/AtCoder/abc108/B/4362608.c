#include <stdio.h>

int main(void)
{
    int x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);
    x_3 = x_2-(y_2-y_1);
    y_3 = y_2+x_2-x_1;
    x_4 = x_3 - (x_2-x_1);
    y_4 = y_3 - (y_2-y_1);
    printf("%d %d %d %d",x_3,y_3,x_4,y_4);
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);
     ^