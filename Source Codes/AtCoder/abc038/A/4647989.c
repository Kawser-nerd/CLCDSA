#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    char s[51];
    scanf("%s",s);
    if(s[strlen(s)-1]=='T') printf("YES");
    else printf("NO");
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^