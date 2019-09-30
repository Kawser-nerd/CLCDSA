#include <stdio.h>
int main(void){
    char A,T,G,C;
    char b,c=0;
    scanf("%c",&b);
    if(b==65)
    c=84;
    if(b==84)
    c=65;
    if(b==71)
    c=67;
    if(b==67)
    c=71;
    
    printf("%c",c);
    return(0);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&b);
     ^