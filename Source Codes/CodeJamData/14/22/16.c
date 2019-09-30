#include<stdio.h>

int main(){
	int t, u;
	scanf("%d", &t);
	for (u = 1 ; u <= t ; ++u){
		int a, b, k, i, j, cnt = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (i = 0 ; i < a ; ++i)
			for (j = 0 ; j < b ; ++j)
				if ((i & j) < k)
					++cnt;
		printf("Case #%d: %d\n", u, cnt);
	}
	return 0;
}
