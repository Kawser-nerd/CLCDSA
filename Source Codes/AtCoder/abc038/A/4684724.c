#include <stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s",s);
    int length = strlen(s);
    if(s[length-1] == 'T')printf("YES\n");
    else printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^