#include <stdio.h>
int main(void){
    int n,l,r,p=0;
    scanf("%d",&n);
    while(n!=0){
        scanf("%d%d",&l,&r);
        p+=r-l+1;
        n--;
    }
    printf("%d\n",p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&l,&r);
         ^