#include <stdio.h>
int main(void){
    int a,b,n,ans=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d%d",&a,&b);
        ans+=a*b;
    }
    ans=ans*1.05;
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^