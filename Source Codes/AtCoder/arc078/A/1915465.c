#include<stdio.h>
#include<math.h>
int main()
{
    long long int suml,sumr=0,min,x;
    int N,i,p=1;
    scanf("%d",&N);
    long long int a[N];
    for(i=0;i<N;i++)
    {
        scanf("%lld",&a[i]);
    }
    suml=a[0];
    for(i=1;i<N;i++)
    {
        sumr=sumr+a[i];
    }
    min=llabs(sumr-suml);
    for(p=1;p<N-1;p++){
    suml=suml+a[p];
    sumr=sumr-a[p];
    x=llabs(sumr-suml);
    if(x<min)
        min=x;
    }
    printf("%lld",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:9: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
     min=llabs(sumr-suml);
         ^
./Main.c:18:9: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:18:9: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^