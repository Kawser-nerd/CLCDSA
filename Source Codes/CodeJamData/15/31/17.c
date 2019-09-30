#include<stdio.h>
int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int ans,t,T,R,C,W;
	scanf("%d",&T);
	for (t=1;t<=T;t++) {
		scanf("%d %d %d",&R,&C,&W);
		ans = 0;
		ans += R*(C/W);
		ans += (W-1);
		if (C%W>0) {
			ans += 1;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}