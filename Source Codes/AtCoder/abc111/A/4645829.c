#include<stdio.h>
int main(){
    char s[3];
    scanf("%s",s);
    for(int i = 0; i < 3; i++){
        if(s[i] == '1'){s[i] = '9';}
        else if(s[i] == '9'){s[i] = '1';}
    }
    printf("%s\n", s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^