#include <stdio.h>
int max(int a, int b){return a>b?a:b;}
int main(void){
    int a,b,ans;
    scanf("%d%d",&a,&b);
    ans=a-b;
    ans=max(ans,900+a%100-b);
    ans=max(ans,a/100*100+90+a%10-b);
    ans=max(ans,a/10*10+9-b);
    ans=max(ans,a-100-b%100);
    ans=max(ans,a-b/100*100-b%10);
    ans=max(ans,a-b/10*10);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^