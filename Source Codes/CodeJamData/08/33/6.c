#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long A[100];
long long seq[1001];
long long len[1001];
long long ans;

void go(){
	int n, m;
	long long X, Y, Z;
	int i, j;
	ans = 0;
	scanf("%d%d%I64d%I64d%I64d", &n, &m, &X, &Y, &Z);
	for(i = 0; i < m; i++)
		scanf("%I64d", &A[i]);
	for(i = 0; i < n; i++){
		seq[i] = A[i % m];
		A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
		// gen
		len[i] = 1;
		for(j = 0; j < i; j++){
			if(seq[j] < seq[i])
				len[i] = (len[i] + len[j]) % 1000000007;
		}
		ans = (ans + len[i]) % 1000000007;
	}
}

int main(){
	int cs, c;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &cs);
	for(c = 1; c <= cs; c++){
		go();
		printf("Case #%d: %I64d\n", c, ans);
	}
	return 0;
}
