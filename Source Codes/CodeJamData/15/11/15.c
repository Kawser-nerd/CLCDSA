#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) 
#define max(a, b) ((a) > (b) ? (a) : (b)) 
int m[10001];

int eat1(int n) {
	int i, mm = 0;
	for (i = 1; i < n; ++i) {
		if (m[i] < m[i-1])
			mm += m[i-1] - m[i];
	}
	return mm;
}

int eat2(int n) {
	int i, r = 0;
	for (i = 1; i < n; ++i)
		if (m[i-1] > m[i])
			r = max(r, m[i-1] - m[i]);
	int e = 0;
	for (i = 1; i < n; ++i) {
		int d;
		if (m[i] > m[i-1])
			d = min(m[i-1], r);
		else if (m[i] <= m[i-1])
			if (m[i-1] < r)
				d = m[i-1];
			else
				d = r;
		e += min(d, r);
	}
	return e;
}

int main() {
	int i, n, t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d\n", &n);
		for (i = 0; i < n; ++i)
			scanf("%d ", &m[i]);
		printf("Case #%d: %d %d\n", x++, eat1(n), eat2(n));
	}
	return 0;
}
