#include <stdio.h>
int main(){
    char s[9];
    int c=0,i=0;
    scanf("%s",s);
    for(;i<3;i++)c+=s[i]=='1';
    printf("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^