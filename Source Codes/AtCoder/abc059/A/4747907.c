#include<stdio.h>
int main(){
    char a[10],b[10],c[10];
    scanf("%s%s%s",a,b,c);
    printf("%c%c%c\n",a[0]-32,b[0]-32,c[0]-32);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a,b,c);
     ^