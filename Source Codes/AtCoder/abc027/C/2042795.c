#include <stdio.h>
#include <math.h>

int main(void){
	long long n;
	int i = 0;
	
	scanf("%lld",&n);
	
	while(n > 2*(powl(4,i)-1)/3-1){
		i = i + 1;
	}
	if(n >= 2*(powl(4,i)-1)/3-pow(4,i-1)){
		printf("Aoki\n");
	}
	else{
		printf("Takahashi\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^