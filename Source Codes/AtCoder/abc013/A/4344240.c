#include <stdio.h>
int main(void){
    // Your code here!
    char a;
    scanf("%c",&a);
    int i = (unsigned char)a;
    printf("%d\n",i-64);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&a);
     ^