#include <stdio.h>
int main(void){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%s\n",x<y?"Better":"Worse");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^