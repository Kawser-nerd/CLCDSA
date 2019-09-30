#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define INF 20000000


int main(){
	long long a,b,c,d,h,e,ans=INF,i,j,n;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&h,&a,&b,&c,&d,&e);	
	ans=c*n;
	for(i=0;i<=n;i++){
		j=(float)((n-i)*e-h-b*i)/(float)(d+e)+1;
		if(i+j<n){
			if(j<0)j=0;
			ans=min(ans,a*i+c*j);
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&h,&a,&b,&c,&d,&e); 
  ^