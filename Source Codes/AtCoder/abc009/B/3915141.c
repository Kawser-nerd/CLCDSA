#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int max = 1;
    int ans = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]>max){
            ans = max;
            max = a[i];
        }
        else if(a[i]<max&&a[i]>=ans){
            ans = a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",a+i);
         ^