import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().solver();
	}

	void solver() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[][] w = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				w[i][j] = sc.nextInt();
			}
		}
		int[] sum = new int[1 << N];
		for (int i = (1 << N) - 1; i >= 1; i--) {
			int s = 0;
			for (int j = 0; j < N; j++) {
				if (((i >> j) & 1) == 1) {
					for (int k = j + 1; k < N; k++) {
						if (((i >> k) & 1) == 1) {
							s += w[j][k];
						}
					}
				}
			}
			sum[i] = s;
		}

		int[] dp = new int[1 << N];
		Arrays.fill(dp, -Integer.MAX_VALUE / 4);
		dp[0] = 0;
		for (int i = 1; i < (1 << N); i++) {
			dp[i] = K;
			for (int j = (i - 1) & i; j >= 1; j = (j - 1) & i) {
				if (sum[i] < sum[i ^ j] + sum[j])
					throw new AssertionError(sum[i] + " " + sum[i ^ j] + " " + sum[j] + " " + Integer.toBinaryString(i)
							+ " " + Integer.toBinaryString(i ^ j) + " " + Integer.toBinaryString(j));
				dp[i] = Math.max(dp[i], dp[i ^ j] - sum[i] + sum[i ^ j] + sum[j] + K);
			}
		}

		System.out.println(dp[(1 << N) - 1]);
	}
}