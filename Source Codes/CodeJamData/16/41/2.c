#include <stdio.h>
#include <string.h>

typedef long long ll;

void rps(int N, int n, int sym) {
	if(n >= N) {
		if(sym == 0) printf("P");
		if(sym == 1) printf("R");
		if(sym == 2) printf("S");
		return;
	}
	if (sym == 0) {
		rps(N, n+2, 0);
		rps(N, n+2, 1);
		rps(N, n+2, 0);
		rps(N, n+2, 2);
	}
	if (sym == 1) {
		rps(N, n+2, 0);
		rps(N, n+2, 1);
		rps(N, n+2, 1);
		rps(N, n+2, 2);
	}
	if (sym == 2) {
		rps(N, n+2, 0);
		rps(N, n+2, 2);
		rps(N, n+2, 1);
		rps(N, n+2, 2);
	}
}

int main() {
	int t, T;
	int N, R, P, S;
	int n, pow, r, p, s, tmp, i, flag;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &N, &R, &P, &S);
		printf("Case #%d: ", t);
		n = N;
		r = R;
		p = P;
		s = S;
		flag = 0;
		pow = 1;
		for(i = 0; i < N - 2; i++) pow *= 2;
		while(n > 1) {
			if(r < pow || p < pow || s < pow) {
				printf("IMPOSSIBLE\n");
				flag = 1;
				break;
			}
			p = p - pow;
			r = r - pow;
			s = s - pow;
			n -= 2;
			pow /= 4;
		}
		if (flag == 1) continue;
		if (n == 1) {
			if(r == 2 || s == 2 || p == 2) {
				printf("IMPOSSIBLE\n");
				continue;
			}
			if(p == 1) rps(N-1, 0, 0);
			if(r == 1) rps(N-1, 0, 1);
			if(s == 1) rps(N-1, 0, 2);
		} else {
			if(p == 1) rps(N, 0, 0);
			if(r == 1) rps(N, 0, 1);
			if(s == 1) rps(N, 0, 2);
		}
		printf("\n");
	}
}
