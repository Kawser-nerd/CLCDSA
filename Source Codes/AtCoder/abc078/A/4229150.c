#include <stdio.h>
int main(){
    char a, b;
    scanf("%c %c", &a, &b);
    if(a == b)
        printf("=\n");
    else if(a < b)
        printf("<\n");
    else
        printf(">\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c %c", &a, &b);
     ^