#include <stdio.h>

int check(int n, int k) {
	while (n--) {
		if (!(k&1))
			return 0;
		k>>=1;
	}
	return 1;
}

int main() {
	int t,n,k,c;
	scanf("%d",&t);
	for (c=1;c<=t;++c) {
		scanf("%d%d",&n,&k);
		if (check(n,k))
			printf("Case #%d: ON\n",c);
		else
			printf("Case #%d: OFF\n",c);
	}
	return 0;
}
