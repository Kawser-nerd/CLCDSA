#include <stdio.h>
#include <string.h>
int main(void){
    long long ans=0,tmp=0;
    char s[200020];
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='B'){
            tmp++;
        } else {
            ans+=tmp;
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^