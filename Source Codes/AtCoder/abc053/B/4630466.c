#include <stdio.h>
#include <string.h>
int main(void){
    char s[200001];
    int i,j;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='A'){
            for(j=strlen(s)-1;j>i;j--){
                if(s[j]=='Z'){
                    printf("%d\n",j-i+1);
                    return 0;
                }
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^