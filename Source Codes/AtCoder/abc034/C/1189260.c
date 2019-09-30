#include<stdio.h>
#define X 1000000007

int main(void){
	long long w,h,n,r,i,j,p[262144]={0},x,res,mem;
	scanf("%lld%lld",&w,&h);
	n = w+h-2;
	r = h-1;
	if(r*2 > n){r = n-r;}
	for(i = 0;i < r;i++){
		x = (n-i);
		for(j = 2;j <= 512;j++){
			if(x == 1){break;}
			if(x%j){continue;}
			while(x%j == 0){p[j]++;x/=j;}
		}
		if(x!=1){p[x]++;}
	}
	for(i = 1;i <= r;i++){
		x = i;
		for(j = 2;j <= 512;j++){
			if(x == 1){break;}
			if(x%j){continue;}
			while(x%j == 0){p[j]--;x/=j;}
		}
		if(x!=1){p[x]--;}
	}
	res = 1;
	for(i = 2;i <= n;i++){
		mem = i;
		while(p[i]){if(p[i]%2){res*=mem;res%=X;}p[i]/=2;mem*=mem;mem%=X;}
	}
	printf("%lld\n",res%X);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&w,&h);
  ^