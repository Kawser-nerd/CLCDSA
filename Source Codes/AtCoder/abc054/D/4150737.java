import java.util.*;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int Ma = sc.nextInt();
		final int Mb = sc.nextInt();
		int[][][] dp = new int[N + 1][N * 10 + 1][N * 10 + 1];

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				for (int k = 0; k < dp[i][j].length; k++) {
					dp[i][j][k] = Integer.MAX_VALUE;
				}
			}
		}
		dp[0][0][0] = 0;

		for (int i = 1; i <= N; i++) {
			int ai = sc.nextInt();
			int bi = sc.nextInt();
			int ci = sc.nextInt();
			for (int j = 0; j < dp[i].length; j++) {
				for (int k = 0; k < dp[i][j].length; k++) {
					if(dp[i-1][j][k] == Integer.MAX_VALUE) {
						continue;
					}
					dp[i][j][k] = Math.min(dp[i - 1][j][k], dp[i][j][k]);
					dp[i][j + ai][k + bi] = Math.min(dp[i - 1][j][k] + ci, dp[i][j + ai][k + bi]);
				}
			}
		}
		int minCost = Integer.MAX_VALUE;
		for (int j = 1; j < dp[N].length; j++) {
			for (int k = 1; k < dp[N][j].length; k++) {
				if ( j * Mb == k * Ma) {
					minCost = Math.min(minCost,dp[N][j][k]);
				}
			}
		}

		if (minCost == Integer.MAX_VALUE) {
			minCost = -1;
		}
		
		System.out.println(minCost);
		sc.close();
	}
}