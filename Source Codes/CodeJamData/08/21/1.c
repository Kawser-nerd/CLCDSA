#include <stdio.h>
#include <stdlib.h>

struct point {
	long long x, y;
} t[111111];

long long cnt[3][3];

int main(void) {
	freopen("input.txt", "r", stdin);
	int i, j, k, m, n, test, T, N, x0, y0;
	long long A, B, C, D, M, p, q, ans, cans;
	
	scanf("%d", &T);
	
	for(test=1; test<=T; test++) {
		scanf("%d %lld %lld %lld %lld %d %d %lld", &N, &A, &B, &C, &D, &x0, &y0, &M);
		
		ans = 0;
		
		p = x0; q = y0;
		t[1].x = p;
		t[1].y = q;
		for (i=2; i<=N; i++) {
			p = (A * p + B) % M;
			q = (C * q + D) % M;
			t[i].x = p;
			t[i].y = q;
		}
		
		for (i=0; i<=2; i++) {
			for (j=0; j<=2; j++) {
				cnt[i][j] = 0;
			}
		}
		
		for (i=1; i<=N; i++) {
			cnt[ t[i].x % 3 ][ t[i].y % 3 ]++;
		}
		
		for (i=1; i<=N; i++) {
			cnt[ t[i].x % 3 ][ t[i].y % 3 ]--;
			cans = 0;
			for (j=0; j<=2; j++) for (k=0; k<=2; k++) {
				for (m=0; m<=2; m++) for (n=0; n<=2; n++) {
					if ( (t[i].x%3 + j + m)%3 == 0 && (t[i].y%3 + k + n)%3 == 0) {
						if ( j == m && k == n ) cans += cnt[j][k] * (cnt[j][k] - 1);
						else cans += cnt[j][k] * cnt[m][n];
					}
				}
			}

			cans /= 2;
			ans += cans;
		}
		
		printf("Case #%d: %lld\n", test, ans);
	}

	return 0;
}
