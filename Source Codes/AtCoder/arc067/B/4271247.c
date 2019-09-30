#include<stdio.h>
int main(){
	long long int N,A,B,n,i,j,t,num=0;
	scanf("%lld%lld%lld",&N,&A,&B);
	scanf("%lld",&n);
	t=n;
	for(i=0;i<N-1;i++){
		scanf("%lld",&n);
		if((n-t)*A<B){
			num+=(n-t)*A;
		}
		else{
			num+=B;
		}
		t=n;
	}
	printf("%lld",num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&N,&A,&B);
  ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^