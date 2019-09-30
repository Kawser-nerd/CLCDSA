#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,min=0,max=0,mini,maxi;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if (max<a[i]){
            max=a[i];
            maxi=i;
        }
        if (min>a[i]){
            min=a[i];
            mini=i;
        }
    }
    if (min==0){
        printf("%d\n",n-1);
        for (int i=1; i<n; i++){
            printf("%d %d\n",i,i+1);
        }
    } else if (max==0){
        printf("%d\n",n-1);
        for (int i=n; i>1; i--){
            printf("%d %d\n",i,i-1);
        }
    } else if (abs(max)>abs(min)){
        printf("%d\n",n*2-1);
        for (int i=0; i<n; i++){
            printf("%d %d\n",maxi+1,i+1);
        }
        for (int i=1; i<n; i++){
            printf("%d %d\n",i,i+1);
        }
    } else {
        printf("%d\n",n*2-1);
        for (int i=0; i<n; i++){
            printf("%d %d\n",mini+1,i+1);
        }
        for (int i=n; i>1; i--){
            printf("%d %d\n",i,i-1);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^