#include <stdio.h>
#include <ctype.h>
int main(void){
    int i;
    char name[13];
    scanf("%s", name);
    for(i=0; name[i]; i++)
        putchar(i ? tolower(name[i]) : toupper(name[i]));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", name);
     ^