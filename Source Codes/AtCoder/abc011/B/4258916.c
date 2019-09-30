#include <stdio.h>
#include <string.h> 
#include <ctype.h>
int main()
{   char s[13];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(i==0){
            printf("%c",toupper(s[i]));
        }
        if(i>0){
            printf("%c",tolower(s[i]));
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^