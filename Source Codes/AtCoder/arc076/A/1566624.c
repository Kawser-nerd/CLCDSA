#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int kaijo(long long int K){
 long long int L;
 if(K==0) return 1;
 L=kaijo(K-1);
 return K*L%1000000007;
 
}

int main(void){
    long long int i,N,M,A;
    scanf("%lld%lld",&N,&M);
    for(;;){
    if(N==M){A=kaijo(N)*kaijo(M)*2%1000000007;break;}
    if(N==M+1||N==M-1){A=kaijo(N)*kaijo(M)%1000000007;break;}
    if(N+1>M||N<M+1){A=0;break;}}


    printf("%lld",A);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&N,&M);
     ^