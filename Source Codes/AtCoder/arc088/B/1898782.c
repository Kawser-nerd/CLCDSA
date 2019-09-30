#include <stdio.h>
#include <string.h>
int min(int x,int y){return x>y?y:x;}
int max(int x,int y){return x>y?x:y;}
int main(void){
    char S[114514];
    scanf("%s",S);
    int ans=1;
    char maemoji=S[0];
    int count=1;
    for(int i=1;i<strlen(S);i++){
        if(S[i]!=maemoji){
            maemoji=S[i];
            ans=max(ans,min(i,strlen(S)-i+count));
            count=1;
        }
        else count++;
        if(i==strlen(S)-1)ans=max(ans,min(i+1,strlen(S)-(i+1)+count));
    }
    printf("%d",ans);
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^