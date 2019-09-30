#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
	long A=0;
	long K=0;
	scanf("%ld",&A);
	scanf("%ld",&K);
	long goukei=A;
	long i=0;
 
if(K>0){
	while(goukei<2000000000000){
		goukei=goukei+1+goukei*K;
		i++;
 
	}}
else{
i=2000000000000-A;
}
	printf("%ld",i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&A);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&K);
  ^