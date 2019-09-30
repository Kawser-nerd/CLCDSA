#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    if(a < 1000){
        printf("ABC\n");
    }else{
        printf("ABD\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^