#include <stdio.h>
int main(void){
    int h,m;
    scanf("%d%d",&h,&m);
    printf("%d\n",(17-h)*60+(60-m));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&m);
     ^