#include <stdio.h>

int main(void){
    int n,ans=1,hl=0;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for (int i=1; i<n; i++){
        if (a[i]<a[i-1]){
            if (hl==0){
                hl=-1;
            } else if (hl==1){
                ans++;
                hl=0;
            }
        } else if (a[i]>a[i-1]){
            if (hl==0){
                hl=1;
            } else if (hl==-1){
                ans++;
                hl=0;
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^