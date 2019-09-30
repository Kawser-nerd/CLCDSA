#include<stdio.h>
int main(void){
    long i,r,k = 0,n,x,a[100000];
    scanf("%ld%ld",&n,&x);
    for(i = 0;i < n;i++){
        scanf("%ld",&a[i]);
    }
    for(i = 0;i < n - 1;i++){
        r = a[i] + a[i + 1] - x;
        if(r > 0){
            if(a[i + 1] >= r){
                a[i + 1] -= r;
            }else{
                a[i + 1] = 0;
            }
            k += r;
        }
    }
    printf("%ld\n",k);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&n,&x);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&a[i]);
         ^