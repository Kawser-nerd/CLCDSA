#include<stdio.h>
int n,a[10001],i,count;
int main(void){
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    for(i = 0;i < n;i++){
        while(a[i]%2 == 0){
            a[i]/=2;
            count += 1;
        }
    }
    printf("%d",count);
    return 0;
        

} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^