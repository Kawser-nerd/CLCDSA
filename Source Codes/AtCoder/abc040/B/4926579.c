#include <stdio.h>
#include <stdlib.h>
int MIN(int a,int b){return a<b?a:b;}
int main()
{
    int n;
    scanf("%d",&n);
    int best=200000,end=sqrt(n)+1;
    for(int i=1;i<=end;i++){
        int tmp=n;
        int sub=tmp%i+abs((tmp-tmp%i)/i-i);
        best=MIN(best,sub);
    }
    
    printf("%d",best);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:25: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
     int best=200000,end=sqrt(n)+1;
                         ^
./Main.c:8:25: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:8:25: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^