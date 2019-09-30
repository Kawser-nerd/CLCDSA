#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i, N;
	long long t;
	int p[20010];
	long long a[20010], b[20010];
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &p[i]);

	for (i=1;i<=N;i++) {
		a[i] = i;
		b[i] = N-i+1;
	}
	t = (N-1) - 2;
	if (t>0) {
		if (a[p[0]] < b[p[0]]) b[p[0]] += t;
		else a[p[0]] += t;
	}
	for (i=1;i<N;i++) {
		t = a[p[i-1]] + b[p[i-1]];
		if (t < a[p[i]] + b[p[i]]) continue;
		else {
			t -= a[p[i]] + b[p[i]];
			if (a[p[i]]<b[p[i]]) {
				b[p[i]] += t+1;
				if (p[i]>1) if (b[p[i]] <= b[p[i]-1]) {
					a[p[i]] += b[p[i]] - (b[p[i]-1]-1);
					b[p[i]] = b[p[i]-1] - 1;
				} 
			} else {
				a[p[i]] += t+1;
				if (p[i]<N) if (a[p[i]] >= a[p[i]+1]) {
					b[p[i]] += a[p[i]] - (a[p[i]+1]-1);
					a[p[i]] = a[p[i]+1] - 1;
				} 
			}
		}
	}

//	for (i=1;i<N;i++) printf("%d ", a[i]); printf("%d\n", a[N]);
//	for (i=1;i<N;i++) printf("%d ", b[i]); printf("%d\n", b[N]);
	for (i=2;i<=N;i++) {
		if (a[i-1]>=a[i]) {
			b[i] += a[i] - a[i-1] - 1;
			a[i] = a[i-1] + 1;
		}
		if (b[i-1]<=b[i]) {
			a[i] += b[i] - b[i-1] + 1;
			b[i] = b[i-1] - 1;			
		}
	}
	if (b[N]<=0) {
		t = 1 - b[N];
		for (i=1;i<=N;i++) b[i] += t;
	}
	if (a[1]<=0) {
		t = 1 - a[1];
		for (i=1;i<=N;i++) a[i] += t;
	}
	for (i=1;i<N;i++) printf("%d ", a[i]); printf("%d\n", a[N]);
	for (i=1;i<N;i++) printf("%d ", b[i]); printf("%d\n", b[N]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:27: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  for (i=1;i<N;i++) printf("%d ", a[i]); printf("%d\n", a[N]);
                           ^
./Main.c:63:48: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  for (i=1;i<N;i++) printf("%d ", a[i]); printf("%d\n", a[N]);
                                                ^
./Main.c:64:27: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  for (i=1;i<N;i++) printf("%d ", b[i]); printf("%d\n", b[N]);
                           ^
./Main.c:64:48: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  for (i=1;i<N;i++) printf("%d ", b[i]); printf("%d\n", b[N]);
                                                ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_re...