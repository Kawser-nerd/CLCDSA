#include <stdio.h>
int main() {
    int n,i;long h=0;scanf("%d",&n);int a[n],b[n];
    for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
    for(i=n-1;i>=0;i--)h+=(b[i]-(a[i]+h)%b[i])%b[i];
    printf("%ld",h);return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n,i;long h=0;scanf("%d",&n);int a[n],b[n];
                      ^
./Main.c:4:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
                     ^