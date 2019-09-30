import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	int n;
	ArrayList<Integer>[] g;
	int[] sz;
	int[] sz2;
	final long MOD = 1_000_000_000 + 7;
	int MAX = 10000;
	long[] fac = new long[MAX];
	long[] ifac = new long[MAX];
	long[] inv = new long[MAX];
	{
		fac[0] = fac[1] = ifac[0] = ifac[1] = inv[0] = inv[1] = 1;
		for (int i = 2; i < MAX; ++i) {
			fac[i] = i * fac[i - 1] % MOD;
			inv[i] = MOD - inv[(int) (MOD % i)] * (MOD / i) % MOD;
			ifac[i] = inv[i] * ifac[i - 1] % MOD;
		}
	}

	long comb(int n, int k) {
		if (n < k || n < 0 || k < 0)
			throw new AssertionError();
		return fac[n] * ifac[n - k] % MOD * ifac[k] % MOD;
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < g.length; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; ++i) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			--x;
			--y;
			g[x].add(y);
			g[y].add(x);
		}
		sz = new int[n];
		sz2 = new int[n];
		dfs(0, -1);
		int comp = n + 1;
		int center = 0;
		for (int i = 0; i < sz2.length; ++i) {
			if (comp > sz2[i]) {
				comp = sz2[i];
				center = i;
			}
		}
		if (n % 2 == 0 && n == comp * 2) {
			System.out.println(fac[n / 2] * fac[n / 2] % MOD);
			return;
		}
		dfs(center, -1);
		int m = g[center].size();
		int[] a = new int[m];
		for (int i = 0; i < m; ++i) {
			int v = g[center].get(i);
			a[i] = sz[v];
		}
		Arrays.sort(a);
		long[][] dp = new long[m + 1][n + 1];
		dp[0][0] = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j + a[i] <= n; ++j) {
				for (int k = 0; k <= a[i]; ++k) {
					dp[i + 1][j + k] += dp[i][j] * comb(a[i], k) % MOD * comb(a[i], k) % MOD * fac[k] % MOD;
					dp[i + 1][j + k] %= MOD;
				}
			}
		}

		long ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans += (i % 2 == 0 ? 1 : MOD - 1) * dp[m][i] % MOD * fac[n - i] % MOD;
			ans %= MOD;
		}
		System.out.println(ans);
	}

	void dfs(int cur, int par) {
		sz[cur] = 1;
		int ma = 0;
		for (int dst : g[cur]) {
			if (dst == par)
				continue;
			dfs(dst, cur);
			sz[cur] += sz[dst];
			ma = Math.max(ma, sz[dst]);
		}
		ma = Math.max(ma, n - sz[cur]);
		sz2[cur] = ma;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.