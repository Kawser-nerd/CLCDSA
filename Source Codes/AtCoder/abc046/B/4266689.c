#include <stdio.h>
int main()
{   int n,k;
    scanf("%d%d",&n,&k);
    long long ans=1;
    for(int i=0;i<n;i++){
        if(i==0){
            ans*=k;
        }else{
            ans*=(k-1);
        }
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^