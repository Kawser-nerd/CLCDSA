#include <stdlib.h>
#include <stdio.h>

int main()
{int n,i;
char s[100001][11];
long long ans=0,counter[5]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%s",s[i]);
    }
    for(i=0;i<n;i++){
        if(s[i][0]=='M'){
            counter[0]++;
        }else if(s[i][0]=='A'){
            counter[1]++;
        }else if(s[i][0]=='R'){
            counter[2]++;
        }else if(s[i][0]=='C'){
            counter[3]++;
        }else if(s[i][0]=='H'){
            counter[4]++;
        }
    }
    ans+=counter[0]*counter[1]*counter[2];
    ans+=counter[0]*counter[1]*counter[3];
    ans+=counter[0]*counter[1]*counter[4];
    ans+=counter[0]*counter[2]*counter[3];
    ans+=counter[0]*counter[2]*counter[4];
    ans+=counter[0]*counter[3]*counter[4];
    ans+=counter[1]*counter[2]*counter[3];
    ans+=counter[1]*counter[2]*counter[4];
    ans+=counter[1]*counter[3]*counter[4];
    ans+=counter[2]*counter[3]*counter[4];
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^