#include <stdio.h>

int main(void){
    char a,b;
    scanf("%c %c",&a,&b);
    a+=0x20;
    if(a==b){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c",&a,&b);
     ^