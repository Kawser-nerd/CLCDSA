#include <stdio.h>
int main(void){
    // Your code here!
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b) printf("%d\n",c/a);
    else printf("%d\n",c/b);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^