#include <stdio.h>
#include <string.h>
int main(void){
    int ans=-1;
    char s[15];
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++){
        if (ans==-1 || ans>10){
            ans=s[i]-'0';
        } else {
            if (s[i]-'0'<10){
                ans=ans*10+s[i]-'0';
            }
            break;
        }
    }
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^