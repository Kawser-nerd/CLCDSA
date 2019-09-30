#include <stdio.h>
int main(void){
    int a,b,i;
    scanf("%d%d",&a,&b);
    for(i=0;i<b;i++){
        if((a+i)%b==0) break;
    }
    printf("%d\n",i);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^