#include <stdio.h>
int main(void){
    long i, cnt=0, ans=0;
    char s[200000];
    scanf("%s", s);
    for(i=0; s[i]; i++)
        s[i]=='B' ? cnt++ : (ans+=cnt);
    printf("%ld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^