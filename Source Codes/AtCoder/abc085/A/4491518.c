#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,X;
    char S[10];
    scanf("%s",&S);
    S[3]='8';
    printf("%s",S);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^