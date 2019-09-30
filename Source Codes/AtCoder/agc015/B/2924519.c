#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    long long ans=0;
    char s[100020];
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='U'){
            ans+=(strlen(s)-i-1)+2*i;
        } else {
            ans+=2*(strlen(s)-i-1)+i;
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^