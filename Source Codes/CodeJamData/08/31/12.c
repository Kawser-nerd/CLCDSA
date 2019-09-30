#include <stdio.h>
int cmp(const void *a, const void *b) {
    int *c, *d;
    c = (int *) a;
    d = (int *) b;
    if (*c > *d)    return -1;
    if (*c < *d)    return 1;
    return 0;
}
int main() {
    int i, j, N, P, K, L;
    int f[1000];
    long long ans;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
	ans = 0;
	scanf("%d %d %d", &P, &K, &L);
	for(j = 0; j < L; j++) {
	    scanf("%d", &f[j]);
	}
	if (P * K < L) {
	    printf("Case #%d: Impossible\n", i);
	    continue;
	}
	qsort(f, L, sizeof(int), cmp);
	for(j = 0; j < L; j++) {
	    ans += (f[j] * (j / K + 1));
	}
	printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}
