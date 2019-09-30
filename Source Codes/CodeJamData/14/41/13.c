#include <stdio.h>

int n,x;
int s[11111];
int num[777];
int no=1;

void solve() {
	int i,r=0,j;
	scanf("%d %d",&n,&x);
	for(i=0;i<=x;i++) num[i]=0;
	for(i=0;i<n;i++) {
		scanf("%d",&s[i]);
		num[s[i]]++;
	}
	for(i=1;i<=x;i++) {
		while(num[i]--) {
			r++;
			for(j=x-i;j;j--) if(num[j]) {
				num[j]--; break;
			}
		}
	}
	printf("Case #%d: %d\n",no++,r);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
