#include<stdio.h>

int main(void){
	int n,k,a,b;
	long ans=0;
	scanf("%d %d",&n,&k);
	for(b=k+1;b<=n;b++){
		ans=ans+(n/b)*(b-k);
		if(n%b>=k){
			ans=ans+((n%b)-(k-1));
		}
		if(k==0){
			ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:9: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
  printf("%lld\n",ans);
         ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^