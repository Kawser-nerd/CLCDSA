#include <stdio.h>
int main(void)
{
    char n[4];
    int i=0;
    scanf("%s", n);

    while(n[i]!='\0'){
        if(n[i]=='1') n[i]='9';
        else if(n[i]=='9') n[i]='1';
        i++;
    }

    printf("%s\n", n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", n);
     ^