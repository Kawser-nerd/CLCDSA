#include <stdio.h>
int main(void){
    char x[2],s[51];
    int i=0;
    scanf("%s%s",x,s);
    while(s[i]!='\0'){
        if(s[i]!=x[0]) printf("%c",s[i]);
        i++;
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",x,s);
     ^