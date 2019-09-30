#include <stdio.h>
#include <string.h>
int main(void){
    char s[27],alpstr[]="abcdefghijklmnopqrstuvwxyz";
    int i,alphash[26];
    for(i=0;i<26;i++){
        alphash[i]=0;
    }
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(strchr(alpstr,s[i])!=NULL){
            alphash[s[i]-0x61]++;
        }
    }
    for(i=0;i<26;i++){
        if(alphash[i]>=2){
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^