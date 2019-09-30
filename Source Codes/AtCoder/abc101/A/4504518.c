#include <stdio.h>
//#include <string.h>

int main(){
    int a;
    char s[4];
    scanf("%s",&s);
    for(int i=0;i<4;i++){
        if(s[i]=='+'){
            a++;
        }else{
            a--;
        }
    }
    printf("%d",a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^