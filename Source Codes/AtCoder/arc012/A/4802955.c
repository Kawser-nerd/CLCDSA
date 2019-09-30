#include <stdio.h>
#include <string.h>
int main(void){
    char day[10];
    scanf("%s",day);
    if(strcmp(day,"Sunday")==0) printf("0\n");
    if(strcmp(day,"Monday")==0) printf("5\n");
    if(strcmp(day,"Tuesday")==0) printf("4\n");
    if(strcmp(day,"Wednesday")==0) printf("3\n");
    if(strcmp(day,"Thursday")==0) printf("2\n");
    if(strcmp(day,"Friday")==0) printf("1\n");
    if(strcmp(day,"Saturday")==0) printf("0\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",day);
     ^