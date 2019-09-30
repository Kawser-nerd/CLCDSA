#include <stdio.h>
#include <string.h>
int main(void){
    char x,s[60];
    scanf("%c%s",&x,s);
    for (int i=0; i<strlen(s); i++){
        if (s[i]!=x){
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c%s",&x,s);
     ^