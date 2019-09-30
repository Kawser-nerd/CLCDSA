import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		char[] op = new char[n];
		op[0] = '+';
		for (int i = 0; i < n; ++i) {
			if (i != 0)
				op[i] = sc.next().charAt(0);
			a[i] = sc.nextLong();
		}

		long[][] dp = new long[n][3];
		for (int i = 0; i < dp.length; ++i) {
			for (int j = 0; j < dp[i].length; ++j) {
				dp[i][j] = -Long.MAX_VALUE / 10;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				dp[0][0] = a[0];
			} else {
				for (int pre = 0; pre <= 2; ++pre) {
					for (int next = op[i] == '-' ? 1 : 0; next <= pre + (op[i] == '-' ? 1 : 0); ++next) {
						if (next <= 2) {
							dp[i][next] = Math.max(dp[i][next], dp[i - 1][pre] + a[i] * (int) Math.pow(-1, next));
						}
					}
				}
			}
		}

		long ans = -Long.MAX_VALUE / 10;
		for (int i = 0; i <= 2; ++i) {
			ans = Math.max(ans, dp[n - 1][i]);
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}