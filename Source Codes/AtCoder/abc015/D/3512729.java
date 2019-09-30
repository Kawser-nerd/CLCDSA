import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int W = sc.nextInt();
		int N = sc.nextInt();
		int K = sc.nextInt();

		int[] width = new int[N];
		int[] value = new int[N];
		for (int i = 0; i < N; i++) {
			width[i] = sc.nextInt();
			value[i] = sc.nextInt();
		}

		int[][][] dp = new int[N+1][W+1][K+1];

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= W; j++) {
				for (int k = 1; k <= K; k++) {
					if (width[i] <= j) {
						dp[i+1][j][k] = Math.max(dp[i][j - width[i]][k-1] + value[i], dp[i][j][k]);
					} else {
						dp[i+1][j][k] = dp[i][j][k];
					}
				}
			}
		}

		System.out.println(dp[N][W][K]);
	}
}