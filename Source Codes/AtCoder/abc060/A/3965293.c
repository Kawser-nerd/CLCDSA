#include <stdio.h>
int main(void){
    char s[10],t[10],u[10];
    scanf("%s %s %s",s,t,u);
    int a,b;
    for(int i=0;s[i]!='\0';i++){
        a=i;
    }
    for(int i=0;t[i]!='\0';i++){
        b=i;
    }
    if(s[a]==t[0]&&t[b]==u[0]) printf("YES");
    else printf("NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s %s",s,t,u);
     ^