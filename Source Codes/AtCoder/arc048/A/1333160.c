#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
     long long int A,B;
    scanf("%lld%lld",&A,&B);
    if(A*B>0)printf("%lld\n",abs(A-B));
    else printf("%lld\n",abs(A-B)-1);
return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:21: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
     if(A*B>0)printf("%lld\n",abs(A-B));
                     ^
./Main.c:8:17: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
     else printf("%lld\n",abs(A-B)-1);
                 ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&A,&B);
     ^