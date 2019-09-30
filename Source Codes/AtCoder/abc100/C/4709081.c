#include <stdio.h>
#include <limits.h>
int main(void)
{
    long int a[10000], ans=0, n, i;
    scanf("%ld", &n);
    for(i=0;i<n;i++){
        scanf("%ld", &a[i]);
    }

    i=0;
    while(i<n){
        if(a[i]%2==0){
            a[i]=a[i]/2;
            ans++;
        }
        else i++;
    }

    printf("%ld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &a[i]);
         ^