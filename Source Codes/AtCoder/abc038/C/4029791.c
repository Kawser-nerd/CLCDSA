#include <stdio.h>

int main()
{   int n;
    scanf("%d",&n);
    int a[n+1];
    a[n]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long ans=n;
    long long check=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]<a[i+1]){
            cnt++;
            check+=cnt;
        }else{
            ans+=check;
            check=0;
            cnt=0;
        }
    }
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^