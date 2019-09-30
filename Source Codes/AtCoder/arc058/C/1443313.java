import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	static final long MODULO = 1_000_000_000 + 7;
	static long[] pow10 = new long[50];
	static int mask;

	public static void main(String[] args) {
		pow10[0] = 1;
		for (int i = 1; i < pow10.length; ++i) {
			pow10[i] = 10 * pow10[i - 1] % MODULO;
		}

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int z = sc.nextInt();
		mask = (1 << (x + y + z)) - 1;
		solve(n, x, y, z);
	}

	static void solve(int n, int x, int y, int z) {
		long[][] dp = new long[n + 1][1 << (x + y + z)];
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int s = 0; s < 1 << (x + y + z); ++s) {
				for (int ne = 1; ne <= 10; ++ne) {
					int ns = (s << ne | 1 << (ne - 1)) & mask;
					if (f(ns, x, y, z))
						continue;
					dp[i][ns] = (dp[i][ns] + dp[i - 1][s]) % MODULO;
				}
			}
		}
		long ans = pow10[n];
		for (long v : dp[n]) {
			ans = (ans - v + MODULO) % MODULO;
		}
		System.out.println(ans);
	}

	static boolean f(int s, int x, int y, int z) {
		boolean ret = true;
		ret &= ((s >> (z - 1)) & 1) > 0;
		ret &= ((s >> (y + z - 1)) & 1) > 0;
		ret &= ((s >> (x + y + z - 1)) & 1) > 0;
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}