#include <stdio.h>
int main(void){
    int a,b,n=0,i;
    scanf("%d%d",&a,&b);
    for(i=1;i<b-a;i++){
        n+=i;
    }
    printf("%d\n",n-a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^