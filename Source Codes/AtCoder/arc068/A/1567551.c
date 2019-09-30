#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    long long int i,j,X,A,B,y;
    scanf("%lld",&X);
    
    if(X<=6){printf("1");exit(0);}
    if(X>6){A=0;}
    for(;;){
        if(X>=11){
            B=X/11;
            A+=2*B;
            X-=B*11;
        }
        if(X==0){break;}
        if(X<=6){A++;break;}
        if(X>6){A+=2;break;}
        

    
        
        }
    

    printf("%lld\n",A);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&X);
     ^