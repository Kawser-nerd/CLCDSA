#include <stdio.h>
int main(){
    char s[100];
    int i;
    scanf("%s%d",&s,&i);
    printf("%c\n",s[i-1]);
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
     scanf("%s%d",&s,&i);
           ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",&s,&i);
     ^