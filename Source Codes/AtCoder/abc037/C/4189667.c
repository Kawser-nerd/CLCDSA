#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    long long sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    long long ans=sum;
    for(int i=k;i<n;i++){
        sum-=a[i-k];
        sum+=a[i];
        ans+=sum;
    }
    printf("%lld",ans);
    
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^