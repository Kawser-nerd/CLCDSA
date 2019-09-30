#include<stdio.h>
#include<math.h>
int main()
{
    long long int b,c,i,j,m=0,n=0;
    scanf("%lld",&i);
    long long int a[i-1];
    for(j=0;j<i;j++){
        scanf("%lld",&a[j]);
        m+=a[j];
        }
    b=llabs(m-2*a[0]);
    for(j=0;j<i-1;j++){
        n+=a[j];
        c=llabs(m-2*n);
        if(c<b) b=c;
    }
    printf("%lld",b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:7: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
     b=llabs(m-2*a[0]);
       ^
./Main.c:12:7: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:12:7: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&i);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[j]);
         ^