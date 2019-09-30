#include<stdio.h>

int main(void){
	long n,m,ans;
	scanf("%ld %ld",&n,&m);
	if(n==1){
		if(m==1){
			ans=1;
		}else if(m==2){
			ans=0;
		}else{
			ans=m-2;
		}
	}else if(n==2){
		ans=0;
	}else{		// n>=3
		if(m==1){
			ans=n-2;
		}else if(m==2){
			ans=0;
		}else{		// m>=3
			ans=(n-2)*(m-2);
		}
	}
	
	printf("%ld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&m);
  ^