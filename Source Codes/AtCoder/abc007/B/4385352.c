#include <stdio.h>
int main(void){
    // Your code here!
    char s[2];
    scanf("%s",s);
    if(s[0]=='a' && s[1]=='\0')
        printf("-1\n");
    else
        printf("a\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^