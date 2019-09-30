#include <stdio.h>

int main(void){
    char s[11];
    scanf("%s",s);
    int i,id=0;
    for(i=0;i<s[i]!='\0';i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            //printf("%c %c\n",s[i],s[i+1]);
            if(s[i+1]-'0'>=0&&s[i+1]-'0'<=9){
                id=(s[i]-'0')*10+s[i+1]-'0';
                break;
            }else{
                id=s[i]-'0';
                break;
            }
        }
    }
    printf("%d\n",id);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^