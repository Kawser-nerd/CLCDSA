#include <stdio.h>

void solve() {
	char s[1001];
	int k,i,j,r=0;
	scanf("%1000s %d",s,&k);
	for(i=0;s[i];i++) if(s[i]=='-') {
		for(j=0;j<k;j++) {
			if(!s[i+j]) { puts("IMPOSSIBLE"); return; }
			s[i+j]^='-'^'+';
		}
		r++;
	}
	printf("%d\n",r);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
