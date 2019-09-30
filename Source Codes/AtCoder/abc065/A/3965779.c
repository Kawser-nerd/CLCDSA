#include <stdio.h>
int main(void){
    int x,a,b;
    scanf("%d%d%d",&x,&a,&b);
    if(a>=b) printf("delicious");
    else if(x>=b-a) printf("safe");
    else  printf("dangerous");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&a,&b);
     ^