#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B;
    char S[30];
    scanf("%s",S);
    A=strlen(S);
    for(int i=0;i<A;i++){
        if((S[i]!='a')&&(S[i]!='i')&&(S[i]!='u')&&(S[i]!='e')&&(S[i]!='o')){
            printf("%c",S[i]);
        }
    }
    printf("\n");
    
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^