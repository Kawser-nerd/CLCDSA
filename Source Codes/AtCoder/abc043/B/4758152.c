#include <stdio.h>
#include <string.h>
int main(void){
    char s[11],t[11]={'\0'};
    int i;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='B') t[strlen(t)-1]='\0';
        else t[strlen(t)]=s[i];
    }
    printf("%s\n",t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^