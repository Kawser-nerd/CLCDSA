import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	final long MODULO = 1_000_000_000 + 7;

	void run() throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();// ??????
		int m = sc.nextInt();// ????
		/*
		 * dp[i][j][k]:=i????????????(k=0????????????k=1??????????j??????????
		 */

		long[][][] dp = new long[2][n + 1][2];
		for (int i = 0; i <= n; ++i) {
			if (i != 0)
				dp[0][i][0] = 1;
			else
				dp[0][i][1] = 1;
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k < 2; ++k) {

					// ????
					if (j - 1 >= 0) {
						if (j - 1 > 0)
							dp[(i + 1) % 2][j - 1][k] += dp[i % 2][j][k];
						else
							dp[(i + 1) % 2][j - 1][1] += dp[i % 2][j][k];
					}
					// ????
					if (j + 1 <= n) {
						dp[(i + 1) % 2][j + 1][k] += dp[i % 2][j][k];
					}

					// ?????????????
					if (j - 1 >= 0) {
						if (j - 1 > 0) {
							dp[(i + 1) % 2][j][k] += dp[i % 2][j][k];
						} else if (j - 1 == 0) {
							dp[(i + 1) % 2][j][1] += dp[i % 2][j][k];
						}
					}

					// ?????????????
					if (j + 1 <= n) {
						dp[(i + 1) % 2][j][k] += dp[i % 2][j][k];
					}

				}
			}
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k < 2; ++k) {
					dp[(i + 1) % 2][j][k] %= MODULO;
				}
			}
			dp[i % 2] = new long[n + 1][2];
		}

		long ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans = (ans + dp[m % 2][i][1]) % MODULO;
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}