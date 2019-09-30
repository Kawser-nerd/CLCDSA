#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    int i,sn=0;
    char n[11];
    scanf("%s",n);
    for(i=0;i<strlen(n);i++){
        sn+=n[i]-0x30;
    }
    printf("%s\n",atoi(n)%sn==0?"Yes":"No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",n);
     ^