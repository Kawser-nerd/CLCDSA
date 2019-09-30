#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){
    char S[5];
    scanf("%s",S);
    int i,ans=0;
    for(i=0;i<4;i++){
        if(S[i]=='+') ans += 1;
        else ans -= 1;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^