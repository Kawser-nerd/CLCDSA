#include <stdio.h>

int main(){
    
    int a, b;
    scanf("%d%d",&a, &b);
    if(a < 9 && b < 9){
        printf("Yay!\n");
    }else{
        printf(":(\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a, &b);
     ^