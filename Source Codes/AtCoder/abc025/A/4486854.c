#include <stdio.h>
int main(void){
    // Your code here!
    char s[6];
    int n;
    scanf("%s%d",s,&n);
    n -= 1;
    printf("%c%c\n",s[n/5],s[n%5]);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&n);
     ^