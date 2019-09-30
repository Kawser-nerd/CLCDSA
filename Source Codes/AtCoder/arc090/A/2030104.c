#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[103]={};
    int b[103]={};
    int tt[103]={0};
    for(int p=0;p<n;p++)
    {
        scanf("%d ",&a[p]);
        for(int r=p;r<n;r++)tt[r]+=a[p];
    }
    for(int q=0;q<n;q++)
    {
        scanf("%d ",&b[q]);
        for(int s=0;s<=q;s++)tt[s]+=b[q];
    }
    
    int ans=0;
    for(int ss=0;ss<n;ss++)
    {
        if(ans<tt[ss])ans=tt[ss];
    }
    printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d ",&a[p]);
         ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d ",&b[q]);
         ^