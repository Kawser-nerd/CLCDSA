#include <stdio.h>
#include <math.h>

#define MIN 1E9
#define MAX -10e+9

long long int i,j;

int main(void){
    int n,a[1000100];
    scanf("%d",&n);
    if(n==0) puts("0");
    i=0;
    while(n!=0){
        a[i]=abs(n)%2;
        if(n<0&&a[i]==1){
            n-=1;
        }
        n/=(-2);
        i++;
    }
    for(j=i-1;j>=0;j--) printf("%d",a[j]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:14: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
         a[i]=abs(n)%2;
              ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^