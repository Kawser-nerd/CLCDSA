import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();
		int k = sc.nextInt();

		double[][] dp = new double[k + 1][n + 1];
		double[][] dp2 = new double[k + 1][n + 1];
		for (int i = 0; i <= k; i++) {
			dp2[i][0] = 1;
		}

		for (int i = 1; i <= n; i++) {
//			double p = (double)1 / i;
			double p = (double)1 / (n - i + 1);
			for (int j = 0; j <= k; j++) {
//				dp[j][i] = dp[j][i - 1] * (1 - p);
//				dp2[j][i] = dp2[j][i - 1] * (1 - p);

				dp[j][i] = dp[j][i - 1] * (1 - p);
				dp2[j][i] = dp2[j][i - 1] * (1 - p);

				double tmp = 0;
				if (j > 0) {
//					dp[j][i] += Math.max(dp[j][i - 1], dp2[j - 1][i - 1]) * p;
//					dp2[j][i] += Math.max(dp[j][i - 1], dp2[j - 1][i - 1]) * p;
					tmp = dp2[j - 1][i - 1] * p;
				} else {
//					dp[j][i] += dp[j][i - 1] * p;
//					dp2[j][i] += dp[j][i - 1] * p;
				}

				dp[j][i] += Math.max(tmp, dp[j][i - 1] * p);
				dp2[j][i] += Math.max(tmp, dp[j][i - 1] * p);
			}
		}

//		double max = 0;
//		for (int i = 0; i <= k; i++) {
//			max = Math.max(max, dp[i][n]);
//		}

//		pr.printf("%.7f\n", max);
		pr.printf("%.7f\n", dp[k][n]);
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}