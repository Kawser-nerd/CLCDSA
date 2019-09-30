#include <stdio.h>
#include <string.h>
int main(void){
    char s[100001],i[1];
    scanf("%s",s);
    for(i[0]=0x61;i[0]<0x7b;i[0]++){
        if(strchr(s,i[0])==NULL) break;
    }
    if(i[0]==0x7b) printf("None\n");
    else printf("%c\n",i[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^