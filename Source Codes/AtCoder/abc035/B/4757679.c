#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char s[100001];
    int t,i,lr=0,ud=0,hatena=0;
    scanf("%s%d",s,&t);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='L') lr++;
        if(s[i]=='R') lr--;
        if(s[i]=='U') ud++;
        if(s[i]=='D') ud--;
        if(s[i]=='?') hatena++;
    }
    if(t==1){
        printf("%d\n",abs(lr)+abs(ud)+hatena);
    }
    if(t==2){
        if(abs(lr)+abs(ud)>=hatena) printf("%d\n",abs(lr)+abs(ud)-hatena);
        else printf("%d\n",(hatena-abs(lr)-abs(ud))%2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&t);
     ^