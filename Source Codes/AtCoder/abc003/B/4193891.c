#include<stdio.h>
#include<string.h>

int main(){
    char s[11];
    char t[11];
    unsigned int i;

    scanf("%s",s);
    scanf("%s",t);

    for(i=0;i<strlen(s);i++){
        if(s[i]==t[i]){continue;}
        else if (s[i] == '@' && strchr("atcoder", t[i]) != NULL) { continue; }
        else if (t[i] == '@' && strchr("atcoder", s[i]) != NULL) { continue; }
        else{printf("You will lose\n");return 0;}
    }
    printf("You can win\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^