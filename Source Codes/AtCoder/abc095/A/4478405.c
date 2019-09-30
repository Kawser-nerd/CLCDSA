#include<stdio.h>
#include<string.h>
int main(void){
    char S[3];
    int i,cou;
    scanf("%s",&S);
    for(i=0;i<3;i++){
        if(S[i]=='o'){
            cou++;
        }
    }
    printf("%d",700+cou*100);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[3]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^