#include <stdio.h>
int main(void){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if (n%(a+b)>a || n%(a+b)==0){
        printf("Bug\n");
    } else {
        printf("Ant\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^