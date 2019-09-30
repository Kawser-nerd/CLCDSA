#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    long long int i,temp,j,S=0,n,a[200000],b[600000];

    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }

b[300000]=a[0];

        if(n%2==0){
j=1;
            for(i=1;i<n/2+1;i++){
                b[300000-i]=a[j];

                b[300000+i]=a[j+1];j+=2;
            }
        }
j=1;
        if(n%2!=0){
            for(i=1;i<n/2+1;i++){
                b[300000+i]=a[j];

                b[300000-i]=a[j+1];j+=2;
             }
       }

            
    for(i=0;i<n;i++){
       printf("%lld",b[300000-n/2+i]);
     if(i!=n-1)               printf(" ");

    }
    



    
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^