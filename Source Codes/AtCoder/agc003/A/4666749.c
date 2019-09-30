#include <stdio.h>
#include <string.h>
int main(void){
    int ns=0,we=0;
    char s[1001];
    scanf("%s",&s);
    if(strchr(s,'N')) ns++;
    if(strchr(s,'S')) ns--;
    if(strchr(s,'W')) we++;
    if(strchr(s,'E')) we--;
    printf("%s\n",ns==0 && we==0?"Yes":"No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[1001]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^