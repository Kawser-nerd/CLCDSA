#include <stdio.h>

int main(){
	int t, n, l, h;
	int a[10000];
	scanf("%d", &t);
	int k, i, j;
	for(k = 1; k <= t; ++k){
		scanf("%d %d %d", &n, &l, &h);
		for(i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(i = l; i <= h; ++i){
			for(j = 0; j < n; ++j)
				if(a[j] % i != 0 && i % a[j] != 0)
					break;
			if(j == n)
				break;
		}
		printf("Case #%d: ", k);
		if(i <= h)
			printf("%d\n", i);
		else
			printf("NO\n");
	}
	return 0;
}
