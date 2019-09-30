#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    int a[100005],b[100005];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&b[i]);
    }
    a[0]=0;
    for(int i=1; i<=n-1; i++){
        a[i]=a[i-1]^b[i-1];
    }
    if((a[n-1]^b[n-1])==0){
        for(int i=0; i<n; i++){
            printf("%d\n",a[i]);
        }
    }
    else printf("-1\n");
    
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b[i]);
         ^