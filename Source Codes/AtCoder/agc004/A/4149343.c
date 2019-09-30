#include <stdio.h>
 
int main(){
  long long int A,B,C,min;
  scanf("%lld %lld %lld",&A,&B,&C);
  if(A%2 && B%2 && C%2){
    min=A*B;
    if(A*C<min)min=A*C;
    if(C*B<min)min=C*B;
    printf("%lld\n",min);
  }else{
    printf("0\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&A,&B,&C);
   ^