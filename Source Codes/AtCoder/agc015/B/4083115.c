#include <string.h>
#include <stdio.h>

int main()
{   char s[100001];
    scanf("%s",s);
    long long ans=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='U'){
            ans+=strlen(s)-(i+1);
            ans+=i*2;
        }else{
            ans+=(strlen(s)-(i+1))*2;
            ans+=i;
        }
    }
    printf("%lld",ans);
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^