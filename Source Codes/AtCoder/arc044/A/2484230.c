#include <stdio.h>
#include <math.h>


int main()
{
    int i,n,j,a,sum=0,nn,t;

    scanf("%d",&n);
    if(n==1){
        printf("Not Prime\n");
        return 0;
    }

    nn=sqrt(n);
    t=n;

    while(t>0){
        sum+=(t%10);
        t/=10;
    }
    
    for(i=2;i<=nn;i++){
        if(n%i==0){
            a=n%10;
            if(a%2!=0 && a!=5 && sum%3!=0){
                printf("Prime\n");
                return 0;
            }
            printf("Not Prime\n");
            return 0;
        }
    }
    printf("Prime\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^