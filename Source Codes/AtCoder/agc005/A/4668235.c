#include <stdio.h>
#include <string.h>
int main(void){
    char s[200001];
    int i,a=0,b=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(b>0){
            if(s[i]=='S') b++;
            else b--;
        }
        else{
            if(s[i]=='T') a++;
            else b++;
        }
    }
    printf("%d\n",a*2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^