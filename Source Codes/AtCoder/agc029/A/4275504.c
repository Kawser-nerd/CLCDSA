#include <stdio.h>

int main () {
    char s[200000];
    long i=0,j=0,ans=0;

    scanf("%s",s);
    while(s[i]!='\0') {
        if(s[i]=='B') j++;
        else ans+=j;
        i++;
    }

    printf("%ld\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^