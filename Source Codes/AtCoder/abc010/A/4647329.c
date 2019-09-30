#include<stdio.h>
#include<string.h>
int main(void){
    char name[20];
    scanf("%s",name);
    strcat(name,"pp");
    printf("%s\n",name);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",name);
     ^