#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%s\n",abs(a)<abs(b)?"Ant":(abs(a)>abs(b)?"Bug":"Draw"));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^