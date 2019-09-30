#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

ll difmax=0;
ll dcnt=0;

int main(){
	int n;
	int t;
	scanf("%d%*d%d",&n,&t);
	n--;
	ll low=t;
	while(n--){
		scanf("%d",&t);
		if(t-low>difmax){
			difmax=t-low;
			dcnt=1;
		}else if(t-low==difmax){
			dcnt++;
		}
		low=min(low,t);
	}
	printf("%lld\n",dcnt);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%*d%d",&n,&t);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^