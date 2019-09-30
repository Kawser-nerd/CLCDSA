#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[n];
    int b[n];
    int sum = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        b[i] = x/pow(2,n-i-1);
        x -= b[i]*pow(2,n-i-1);
    }
    for(int i = 0;i<n;i++){
        
        sum += a[i]*b[n-i-1];
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&x);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",a+i);
         ^