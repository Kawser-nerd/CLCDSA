import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	final long MODULO = 924844033L;

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		ArrayList<Integer>[] g = new ArrayList[2 * n];
		for (int i = 0; i < 2 * n; ++i)
			g[i] = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			for (int di = -k; di <= k; di += 2 * k) {
				int nj = i + di;
				if (!(0 <= nj && nj < n)) {
					continue;
				}
				g[i].add(nj + n);
				g[nj + n].add(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (vis[i])
				continue;
			++cnt[dfs(i, -1, g)];
		}
		long[][][] dp2 = new long[1 + cnt.length][1 + cnt.length][2];
		// #get,sz,bool
		dp2[1][1][1] = 1;
		dp2[0][1][0] = 1;

		for (int sz = 2; sz < cnt.length; ++sz) {
			for (int get = 0; get <= sz; ++get) {
				if (get + 1 <= sz) {
					dp2[get + 1][sz][1] += dp2[get][sz - 1][0];
					if (dp2[get + 1][sz][1] >= MODULO)
						dp2[get + 1][sz][1] -= MODULO;
				}
				dp2[get][sz][0] += dp2[get][sz - 1][0] + dp2[get][sz - 1][1];
				if (dp2[get][sz][0] >= MODULO)
					dp2[get][sz][0] -= MODULO;
			}
		}
		long[] dp = new long[n + 1];
		dp[0] = 1;
		for (int sz = 1; sz < cnt.length; ++sz) {
			if (cnt[sz] == 0)
				continue;
			for (int t = 0; t < cnt[sz]; ++t) {
				long[] ndp = Arrays.copyOf(dp, dp.length);
				for (int get = 1; get <= sz; ++get) {
					for (int cur = n - get; cur >= 0; --cur) {
						ndp[cur + get] += (dp2[get][sz][0] + dp2[get][sz][1]) % MODULO * dp[cur] % MODULO;
						ndp[cur + get] %= MODULO;
					}
				}
				dp = Arrays.copyOf(ndp, dp.length);
			}
		}
		long[] fac = new long[n + 1];
		fac[0] = 1;
		for (int i = 1; i < fac.length; ++i) {
			fac[i] = fac[i - 1] * i % MODULO;
		}

		long res = 0;
		for (int i = 1; i < dp.length; ++i) {
			res += fac[n - i] * dp[i] * (int) (Math.pow(-1, (i + 1) % 2)) % MODULO;
			res %= MODULO;
		}
		long ans = (fac[n] - res + MODULO) % MODULO;
		System.out.println(ans);

	}

	long[] cnt = new long[2000];
	boolean[] vis = new boolean[4001];

	int dfs(int cur, int par, ArrayList<Integer>[] g) {
		vis[cur] = true;
		int ret = 0;
		for (int dst : g[cur]) {
			if (dst == par)
				continue;
			if (vis[dst])
				throw new AssertionError();
			ret += dfs(dst, cur, g) + 1;
		}
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.