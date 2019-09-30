import java.util.Arrays;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			System.out.printf("%.9f\n", solve());
		}
	}

	static double solve() {
		int N = sc.nextInt();
		int K = sc.nextInt();
		double[] Pt = new double[N];
		for (int i = 0; i < N; ++i) {
			Pt[i] = sc.nextDouble();
		}
		Arrays.sort(Pt);
		double[] P = new double[K];
		double ans = 0;
		for (int u = 0; u <= K; ++u) {
			for (int i = 0; i < u; ++i) {
				P[i] = Pt[i];
			}
			for (int i = u; i < K; ++i) {
				P[i] = Pt[N - 1 - (i - u)];
			}
			double[][] dp = new double[K + 1][K + 1];
			dp[0][0] = 1;
			for (int i = 1; i <= K; ++i) {
				for (int j = 0; j <= i; ++j) {
					if (j == 0) {
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] * (1 - P[i - 1]));
					} else {
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] * (1 - P[i - 1]) + dp[i - 1][j - 1] * P[i - 1]);
					}
				}
			}
			ans = Math.max(ans, dp[K][K / 2]);
		}
		return ans;
	}

}
