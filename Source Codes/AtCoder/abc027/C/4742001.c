#include <stdio.h>

int main(void){
	long long n,i;
	scanf("%lld",&n);
	int depth=0;
	for(i=n;i>0;i/=2)depth++;
	i=1;
	int taka=1;
	if(depth%2==0){
		while(i<=n){
			if(taka){
				i*=2;
				taka=0;
			}else{
				i = i*2+1;
				taka=1;
			}
		}
	}else{
		while(i<=n){
			if(taka){
				i = 2*i+1;
				taka=0;
			}else{
				i = i*2;
				taka=1;
			}
		}
	}
	if(taka) printf("Takahashi\n");
	else printf("Aoki\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^