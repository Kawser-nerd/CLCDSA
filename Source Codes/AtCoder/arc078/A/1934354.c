#include<stdio.h>
#include<math.h>
long long int a[200012],value[200010];
int main ()
{
    long long int n,i,min,sum=0,sum2=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(i=1;i<n;i++){
        sum2+=a[n-i+1];
        value[i]=llabs(sum-sum2-sum2);
    }
    min=value[i-1];
    for(i=1;i<n;i++)
        if(value[i]<min)
            min=value[i];
    printf("%lld\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:18: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
         value[i]=llabs(sum-sum2-sum2);
                  ^
./Main.c:14:18: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:14:18: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^