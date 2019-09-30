#include <stdio.h>

int a[100000];

int main(){
    int k;
    long long min = 2, max = 2;
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    for(int i=k-1; i>=0; i--){
        min = ((min - 1) / a[i] + 1) * a[i];
        max = (max / a[i] + 1) * a[i] - 1;
        if(max < min){
            puts("-1");
            return 0;
        }
    }
    printf("%lld %lld\n", min, max);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^