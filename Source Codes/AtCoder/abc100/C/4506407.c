#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    int a[n];
    int ans;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        while(a[i]%2==0){a[i]/=2;ans++;}
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^