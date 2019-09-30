#include <stdio.h>

int main()
{   int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    long long ans=0;
    for(int i=0;i<n;i++){
        if(i<k)ans+=x;
        else ans+=y;
    }
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&n,&k,&x,&y);
     ^