#include<stdio.h>
#include<stdlib.h>
int g[101];
int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int cases;
	scanf("%d", &cases);
	int cc;
	for(cc=1; cc<=cases; cc++){
		int n,a;
		scanf("%d%d", &a, &n);
		int i;
		for(i=0;i<n;i++)
			scanf("%d", g+i);
		qsort(g, n, sizeof(int), cmp);
		int addc=0;
		int ans=n;
		if(a > 1){
			for(i=0;i<n;i++){
				while(a<=g[i]){
					a+=a-1;
					addc++;
				}
				a+=g[i];
				if(addc+n-i-1 < ans)
					ans = addc+n-i-1;
			}
		}
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}
