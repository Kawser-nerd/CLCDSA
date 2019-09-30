#include<stdio.h>

int main() {
	int cs=0,N,n,t,i,ret;
	char s[1024];

	for(scanf("%d",&N);N--;) {
		scanf("%d %s",&n,s);
		for(i=ret=t=0;i<=n;i++) {
			if (t<i && s[i]>'0') {
				ret+=i-t;
				t=i;
			}
			t+=s[i]-'0';
		}
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}