#include <stdlib.h>
#include <stdio.h>

int main()
{   int n,t;
    scanf("%d%d",&n,&t);
    long long ans=0;
    int a[n+1];
    a[n]=114515810;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i+1]>=a[i]+t){
            ans+=t;
        }
        else{
            ans+=a[i+1]-a[i];
        }
    }
    printf("%lld\n",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&t);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^