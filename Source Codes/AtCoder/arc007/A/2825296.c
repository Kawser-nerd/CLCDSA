#include<stdio.h>
int main(void){
    int i=0;
    char x,s[50];
    scanf("%c",&x);
    scanf("%s",s);
    while(s[i]){
        if(s[i]==x){
            i++;
            continue;
        }
        printf("%c",s[i]);
        i++;
    }
    putchar('\n');
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&x);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^