#include <stdio.h>
#include <string.h>
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int main(void){
    char s[100020];
    scanf("%s",s);
    int ans=strlen(s);
    for (int i=1; i<strlen(s); i++){
        if (s[i]==s[i-1]){
        } else {
            ans=min(ans,max(i,strlen(s)-i));
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^