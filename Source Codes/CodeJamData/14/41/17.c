#include <stdio.h>
#include <stdlib.h>
int g[10000];
int cmp(const void *a, const void *b){
	return *(const int *)a-*(const int *)b;
}
int main(){
	int tc;
	int p;
	scanf("%d", &tc);
	for(p = 1; p <= tc; p++){
		int n,t;
		scanf("%d%d", &n, &t);
		int i;
		for(i=0;i<n;i++)
			scanf("%d", g+i);
		qsort(g, n, sizeof(int), cmp);
		int lo = 0, hi = n-1;
		int ans = 0;
		while(lo < hi){
			if (g[hi]+g[lo]<=t){
				lo++;
				hi--;
				ans++;
			}else{
				hi--;
				ans++;
			}
		}
		if (lo == hi)
			ans++;
		printf("Case #%d: %d\n", p, ans);
	}
	return 0;
}
