#include <stdio.h>
int Min(int a,int b){
    return a<=b?a:b;
}
int main()
{   int n,k;
    scanf("%d%d",&n,&k);
    int x[n];
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=2*Min(k-x[i],x[i]);
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[i]);
         ^