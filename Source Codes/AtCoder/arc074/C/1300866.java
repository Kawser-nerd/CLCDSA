import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	int n, m;
	int[] l, r, x;
	long MODULO = 1_000_000_000 + 7;

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		l = new int[m];
		r = new int[m];
		x = new int[m];
		for (int i = 0; i < m; ++i) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
			x[i] = sc.nextInt();
		}

		int[][][] dp = new int[n + 1][n + 1][n + 1];
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i != 1) {
				for (int a = 0; a < i - 1; ++a) {
					for (int b = 0; b < i - 1; ++b) {
						dp[i][a][b] = add(dp[i][a][b], dp[i - 1][a][b]);
						dp[i - 1][i][b] = add(dp[i - 1][i][b], dp[i - 1][a][b]);
						dp[i - 1][a][i] = add(dp[i - 1][a][i], dp[i - 1][a][b]);
						dp[i][i - 1][b] = add(dp[i][i - 1][b], dp[a][i - 1][b]);
						dp[a][i][b] = add(dp[a][i][b], dp[i - 1][a][b]);
						dp[a][i - 1][i] = add(dp[a][i - 1][i], dp[a][i - 1][b]);
						dp[i][b][i - 1] = add(dp[i][b][i - 1], dp[a][b][i - 1]);
						dp[a][i][i - 1] = add(dp[a][i][i - 1], dp[a][b][i - 1]);
						dp[a][b][i] = add(dp[a][b][i], dp[a][b][i - 1]);
					}
				}
			} else {
				dp[1][0][0] += dp[0][0][0];
				dp[0][1][0] += dp[0][0][0];
				dp[0][0][1] += dp[0][0][0];
			}
			for (int j = 0; j < m; ++j) {
				if (r[j] != i)
					continue;
				for (int a = 0; a < i; ++a) {
					for (int b = 0; b < i; ++b) {
						int cnt = 1;
						if (a >= l[j])
							++cnt;
						if (b >= l[j])
							++cnt;
						if (cnt != x[j]) {
							dp[i][a][b] = 0;
							dp[a][i][b] = 0;
							dp[a][b][i] = 0;
						}
					}
				}
			}
		}
		long ans = 0;
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				ans += dp[n][a][b];
				ans += dp[a][n][b];
				ans += dp[a][b][n];
				while (ans >= MODULO)
					ans -= MODULO;
			}
		}
		System.out.println(ans);
	}

	int add(int a, int b) {
		int ret = a + b;
		while (ret >= MODULO) {
			ret -= MODULO;
		}
		return ret;
	}

	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}