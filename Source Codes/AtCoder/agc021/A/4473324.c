#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

long long ans;
int m[41];

int solve(int kt,int hn,long long then){
	//printf("%lld\n",ans);
	if(hn==0){
		ans=max(ans,then+9*(kt+1));
		return 0;
	}else{
		if(kt!=0){
			solve(kt-1,1,then+m[kt]);
			if(m[kt]>0)solve(kt-1,0,then+m[kt]-1);
			return 0;
		}else {
			ans=max(ans,then+m[kt]);
			return 0;
		}
	}
}

int main(){
	int i;
	long long n;
	scanf("%lld",&n);
	for(i=0;i<40;i++){
		m[i]=n%10;
		n/=10;
	}
	solve(40,1,0);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^