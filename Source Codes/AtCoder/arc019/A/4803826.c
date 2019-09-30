#include <stdio.h>
#include <string.h>
int main(void){
    char s[9];
    int i;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='O') printf("0");
        else if(s[i]=='D') printf("0");
        else if(s[i]=='I') printf("1");
        else if(s[i]=='Z') printf("2");
        else if(s[i]=='S') printf("5");
        else if(s[i]=='B') printf("8");
        else printf("%c",s[i]);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^