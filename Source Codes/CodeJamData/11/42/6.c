#include <stdio.h>

typedef long long ll;

char mass[510][510];
ll commsum[510][510][3]; //first weighted with 1, second with i, third with j

#define get(t, i0, i1, j0, j1) (commsum[i1+1][j1+1][t]-commsum[i0][j1+1][t]-commsum[i1+1][j0][t]+commsum[i0][j0][t])

int good(ll k, ll a, ll b)
{
	ll sum, isum, jsum;
/*
	if (k == 5 && a == 1 && b == 1) {
		fprintf(stderr, ".");
	}
*/
	sum = get(0, a, a+k-1, b, b+k-1)-mass[a][b]-mass[a+k-1][b]-mass[a][b+k-1]-mass[a+k-1][b+k-1];
	isum = get(1, a, a+k-1, b, b+k-1)-a*mass[a][b]-(a+k-1)*mass[a+k-1][b]-a*mass[a][b+k-1]-(a+k-1)*mass[a+k-1][b+k-1];
	jsum = get(2, a, a+k-1, b, b+k-1)-b*mass[a][b]-b*mass[a+k-1][b]-(b+k-1)*mass[a][b+k-1]-(b+k-1)*mass[a+k-1][b+k-1];
	if (sum*(2*a+k-1) != 2*isum) {
		return 0;
	}
	if (sum*(2*b+k-1) != 2*jsum) {
		return 0;
	}
	return 1;
}

int main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		ll r, c, d, i, j, k, s, lk, rk;
		scanf("%d %d %d\n", &r, &c, &d);
		for (i = 0; i < r; i++) {
			gets(mass[i]);
			for (j = 0; j < c; j++) {
				mass[i][j] -= '0';
			}
		}
		for (i = 0; i < r; i++) commsum[i][0][0] = commsum[i][0][1] = commsum[i][0][2] = 0;
		for (i = 0; i < c; i++) commsum[0][i][0] = commsum[0][i][1] = commsum[0][i][2] = 0;
		for (i = 1; i <= r; i++) {
			for (j = 1; j <= c; j++) {
				commsum[i][j][0] = commsum[i][j-1][0]+mass[i-1][j-1];
				commsum[i][j][1] = commsum[i][j-1][1]+(i-1)*mass[i-1][j-1];
				commsum[i][j][2] = commsum[i][j-1][2]+(j-1)*mass[i-1][j-1];
			}
			for (j = 1; j <= c; j++) {
				commsum[i][j][0] += commsum[i-1][j][0];
				commsum[i][j][1] += commsum[i-1][j][1];
				commsum[i][j][2] += commsum[i-1][j][2];
			}
		}
		lk = 3;
		rk = r < c ? r : c;
		for (k = rk; k >= lk; k--) {
			for (i = 0; i <= r-k; i++) {
				for (j = 0; j <= c-k; j++) {
					if (good(k, i, j)) {
						printf("Case #%d: %d\n", ti, k);
						goto next;
					}
				}
			}
		}
		printf("Case #%d: IMPOSSIBLE\n", ti);
next:	;
	}
	return 0;
}