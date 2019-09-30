#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    char n[51],m[51];
    scanf("%s%s",n,m);
    if(strlen(n)>strlen(m))
        printf("%s\n",n);
    else
        printf("%s\n",m);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",n,m);
     ^