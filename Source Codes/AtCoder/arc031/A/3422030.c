#include <stdio.h>
#include <string.h>
int main(void){
    char s[120];
    scanf("%s",s);
    for (int i=0; i<strlen(s)/2; i++){
        if (s[i]!=s[strlen(s)-1-i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^