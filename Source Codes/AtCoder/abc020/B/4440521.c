#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    char a[7],b[7];
    int n;
    scanf("%s%s",a,b);
    strcat(a,b);
    n = atoi(a);
    printf("%d\n",n*2);
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
     n = atoi(a);
         ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",a,b);
     ^