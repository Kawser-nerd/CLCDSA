#include <stdio.h>

#define N 200000

long a[N+1];

int main(void){
    long n;
    scanf("%ld", &n);
    a[0] = -1;
    for(long i=1; i<=n; i++){
        scanf("%ld", a+i);
    }
    long count=-1;
    for(long i=n; i>=1; i--){
        long d = a[i]-a[i-1];
        if(d>=2){
            puts("-1");
            return 0;
        }else if(d==1){
            count++;
        }else{
            count += a[i];
        }
    }
    printf("%ld\n", count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", a+i);
         ^