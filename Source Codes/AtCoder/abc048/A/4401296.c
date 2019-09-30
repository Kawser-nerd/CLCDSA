#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char a[10],s[100],c[10];
    scanf("%s%s%s",a,s,c);
    printf("A%cC",s[0]);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a,s,c);
     ^