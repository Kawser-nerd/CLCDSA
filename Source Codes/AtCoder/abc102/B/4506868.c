#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    int m,M;
    int a[n];scanf("%d",&a[0]);m=a[0],M=a[0];
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(m>a[i]) m=a[i];
        if(M<a[i]) M=a[i];
    }   
    printf("%d",M-m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^
./Main.c:6:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int a[n];scanf("%d",&a[0]);m=a[0],M=a[0];
              ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^