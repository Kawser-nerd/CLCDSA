#include <stdio.h>
#include <string.h>

int main(void){
    char a[50],b[50];
    int a_len, b_len;
    scanf("%s",a);
    scanf("%s",b);
    a_len = strlen(a);
    b_len = strlen(b);
    if(a_len>b_len) printf("%s\n",a);
    else            printf("%s\n",b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",b);
     ^