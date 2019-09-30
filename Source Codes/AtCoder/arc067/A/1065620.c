#include<stdio.h>
#define X 1000000007

int main(void){
	unsigned long long int si[1024]={0},p[1024]={0},in,i,j,r=1,mem;
	scanf("%llu",&in);
	for(i = 2;i <= 1023;i++){
		if(p[i] == 0){
			for(j = 2*i;j <= 1023;j+=i){p[j] = 1;}
		}
	}
	for(i = 2;i <= in;i++){
		mem = i;
		for(j = 2;j <= 1023;j++){
			if(p[j] == 1){continue;}
			while(!(mem % j)){si[j]++;mem/=j;}
		}
	}
	for(i = 2;i <= 1023;i++){
		r*=(si[i]+1);r%=X;
	}
	printf("%llu\n",r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu",&in);
  ^