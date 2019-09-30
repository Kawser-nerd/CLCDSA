#include <stdio.h>

int main(void) {
    int i,n,max,ans;
    scanf("%d",&n);
    int x[n];
    ans=0;
    for (i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    max=x[0];
    for (i=0;i<n;i++) {
        if (x[i]>=max)
            max=x[i];
    }
    for (i=0;i<n;i++) {
        ans+=x[i];
    }
    printf("%d",ans-max/2);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[i]);
         ^