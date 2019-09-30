#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,cou;
    char S[4];
    scanf("%s",&S);
    for(int i=0;i<4;i++){
        if(S[i]=='+'){
            cou++;
        }else{
            cou--;
        }
    }
    
    printf("%d",cou);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^