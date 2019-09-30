#include<stdio.h>

 


int main(void){
    char s[110];
    int a=0;
    scanf("%s",&s);
    
    for(int i=0;s[i]!='\0';i++){
        a++;
    }

    printf("%c%d%c",s[0],a-2,s[a-1]);

    return 0;


} ./Main.c: In function ‘main’:
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[110]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^