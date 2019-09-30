#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int i,min=1000;
    char s[11];
    scanf("%s",s);
    for(i=0;i<strlen(s)-2;i++){
        if(abs((s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0')-753)<min) min=abs((s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0')-753);
    }
    printf("%d\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^