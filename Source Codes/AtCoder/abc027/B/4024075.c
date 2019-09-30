#include <stdio.h>

int main()
{   int n;
    scanf("%d",&n);
    int a[n],sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%n!=0){
        printf("-1\n");
        return 0;
    }
    int ave=sum/n;
    int cnt=0,sub=0,ans=0;
    for(int i=0;i<n;i++){
        cnt++;
        sub+=a[i];
        if(sub==cnt*ave){
            ans+=cnt-1;
            cnt=0;
            sub=0;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^