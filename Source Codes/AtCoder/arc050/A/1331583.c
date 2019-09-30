#include <stdio.h>
    int main(void){
    int C,c;
    scanf("%c %c",&C,&c);
    puts(C-'A'+'a'==c?"Yes":"No");
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%c %c",&C,&c);
           ^
./Main.c:4:11: warning: format ‘%c’ expects argument of type ‘char *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c",&C,&c);
     ^