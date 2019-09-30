#include <stdio.h>

int main(){
    char x,s[50];
    int i=0;

    scanf("%c",&x);
    scanf("%s",s);
    
    while(s[i]){
        if(s[i]!=x)putchar(s[i]);
        i++;
    }
    putchar('\n');
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&x);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^