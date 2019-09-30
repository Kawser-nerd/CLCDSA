#include <stdio.h>
#include <string.h>
int main(void){
    char s[100001];
    int i;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(i%2==0) printf("%c",s[i]);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^