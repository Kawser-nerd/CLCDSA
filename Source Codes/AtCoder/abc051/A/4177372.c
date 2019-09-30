#include<stdio.h>

int main(){
    char s[20];
    int i;

    scanf("%s",s);

    for(i=0;s[i]!='\0';i++){
        if(s[i]==','){
            s[i] = ' ';
        }
    }
    printf("%s",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^