#include <stdio.h>
#include <string.h>
char str[100001];
int main(void){
    int res=0;
    scanf("%s",str);
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='p') res--;
    }
    printf("%d\n",res+len/2);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^