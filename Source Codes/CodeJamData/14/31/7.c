#include<stdio.h>

long long gcd(long long p, long long q){
	while ((p %= q) && (q %= p));
	return p + q;
}

int main(){
	int t, u;
	scanf("%d", &t);
	for (u = 1 ; u <= t ; ++u){
		long long p, q, g;
		scanf("%lld/%lld", &p, &q);
		g = gcd(p, q);
		p /= g, q /= g;
		if ((q & -q) == q){
			int i;
			for (i = 1, q >>= 1 ; q > 0 ; ++i, q >>= 1)
				if (p & q)break;
			printf("Case #%d: %d\n", u, i);
		}
		else printf("Case #%d: impossible\n", u);
	}
	return 0;
}
