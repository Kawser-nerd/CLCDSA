# include <cstdio>

# define REP(i, n) for (int i = 1; i <= n; ++ i)
# define REP_D(i, n) for (int i = n; i >= 1; -- i)

# define NR 201000

const int M = 2002, M2 = 4010, M4 = 8050;
const int mod = 1000000007;

int n, x[NR], y[NR];
int a[M2 + 10][M2 + 10];
int fac[M4 + 10], fac_inv[M4 + 10];

int pr (int a, int z) { int s = 1; do { if (z & 1) s = 1ll * s * a % mod; a = 1ll * a * a % mod; } while (z >>= 1); return s; }
int binom (int n, int k) { return n < k ? 0 : 1ll * fac[n] * fac_inv[k] % mod * fac_inv[n - k] % mod; }

void inc (int &x, int y) { x = (x + y) % mod; }
void dec (int &x, int y) { x = (x + mod - y) % mod; }

int main () {
	scanf ("%d", &n);
	fac[0] = fac_inv[0] = 1;
	REP (i, M4) fac[i] = 1ll * fac[i - 1] * i % mod;
	fac_inv[M4] = pr (fac[M4], mod - 2);
	REP_D (i, M4 - 1) fac_inv[i] = 1ll * fac_inv[i + 1] * (i + 1) % mod;
	
	REP (i, n) scanf ("%d%d", &x[i], &y[i]), ++ a[M - x[i]][M - y[i]];
	REP (i, M2) REP (j, M2) inc (a[i][j], a[i][j - 1] + a[i - 1][j]);
	int ans = 0;
	REP (i, n) inc (ans, a[M + x[i]][M + y[i]]);
	//printf ("!%d\n", ans);
	REP (i, n) dec (ans, binom (2 * x[i] + 2 * y[i], 2 * x[i]));//, printf ("!%d %d\n", i, binom (2 * x[i] + 2 * y[i], 2 * x[i]));
	//printf ("!%d\n", ans);
	printf ("%lld\n", 1ll * ans * ((mod + 1) / 2) % mod);
	return 0;
}