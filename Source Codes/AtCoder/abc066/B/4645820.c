#include <stdio.h>
#include <string.h>
int main(void){
    char str[201];
    int n,i;
    scanf("%s",str);
    n=strlen(str);
    for(i=n-2;i;i-=2){
        if(strncmp(str,str+i/2,i/2)==0){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^