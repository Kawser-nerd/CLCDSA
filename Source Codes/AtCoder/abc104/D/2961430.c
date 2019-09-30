#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int mod=1000000007;
    char s[100020];
    scanf("%s",s);
    long long ans[strlen(s)+1][4];
    ans[strlen(s)][3]=1,ans[strlen(s)][2]=0,ans[strlen(s)][1]=0,ans[strlen(s)][0]=0;
    for (int i=strlen(s)-1; i>=0; i--){
        if (s[i]=='?'){
            ans[i][3]=(ans[i+1][3]*3)%mod;
            ans[i][2]=(ans[i+1][2]*3+ans[i+1][3])%mod;
            ans[i][1]=(ans[i+1][1]*3+ans[i+1][2])%mod;
            ans[i][0]=(ans[i+1][0]*3+ans[i+1][1])%mod;
        } else if (s[i]=='A'){
            ans[i][3]=(ans[i+1][3])%mod;
            ans[i][2]=(ans[i+1][2])%mod;
            ans[i][1]=(ans[i+1][1])%mod;
            ans[i][0]=(ans[i+1][0]+ans[i+1][1])%mod;
        } else if (s[i]=='B'){
            ans[i][3]=(ans[i+1][3])%mod;
            ans[i][2]=(ans[i+1][2])%mod;
            ans[i][1]=(ans[i+1][1]+ans[i+1][2])%mod;
            ans[i][0]=(ans[i+1][0])%mod;
        } else if (s[i]=='C'){
            ans[i][3]=(ans[i+1][3])%mod;
            ans[i][2]=(ans[i+1][2]+ans[i+1][3])%mod;
            ans[i][1]=(ans[i+1][1])%mod;
            ans[i][0]=(ans[i+1][0])%mod;
        }
    }
    printf("%lld\n",ans[0][0]%mod);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^