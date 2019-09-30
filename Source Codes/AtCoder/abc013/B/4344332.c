#include <stdio.h>
#include<stdlib.h>
int main(void){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    if(10-abs(a-b)>abs(a-b)) printf("%d\n",abs(b-a));
    else printf("%d\n",10-abs(a-b));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^