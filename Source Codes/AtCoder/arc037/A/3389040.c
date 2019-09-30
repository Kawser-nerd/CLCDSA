#include <stdio.h>
int main(void){
    int n,m,ans=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&m);
        if (80-m>0){
            ans+=80-m;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m);
         ^