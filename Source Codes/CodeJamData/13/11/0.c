#include <stdio.h>
typedef long long ll;
int main() {
	int T,no=1;
	ll r,t;
	ll use,num;
	scanf("%d",&T);
	while(T--) {
		scanf("%I64d %I64d",&r,&t);
		use=0; num=0;
		while(1) {
			use+=r+r+(2*num+1)*(2*num+1)-4*num*num;
			if(use>t) break;
			num++;
		}
		printf("Case #%d: %I64d\n",no++,num);
	}
	return 0;
}
