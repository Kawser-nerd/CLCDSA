#include <stdio.h>
int n,i;
int t[5005];
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		int k,j,l,d;
		scanf("%d",&k);
		for(j=0;j<k;j++) t[j] = 0;
		for(j=l=0;j<k-1;) {
			t[l] = ++j;
//			printf("%d - %d\n",j,l);
			for(d=0;d<j+1;l=(l+1)%k,d+=!t[l]);// printf("> %d %d\n",d,l);
		}
		printf("Case #%d:",i+1);
		scanf("%d",&l);
		for(j=0;j<l;j++) {
			scanf("%d",&d);
			printf(" %d",t[d-1]?t[d-1]:k);
		}
		puts("");
	}
	return 0;
}
