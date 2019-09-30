#include<stdio.h>
int main(){
    int a[3],b[3],ans = 0;
    for(int i;i<3;i++){
        scanf("%d%d",&a[i],&b[i]);
        ans += a[i]*b[i]/10;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^