import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int a = sc.nextInt();
		int[] d = new int[51];
		for (int i = 0;i < n;i++) d[i] = sc.nextInt();
		long[][][] dp = new long[60][60][2510];
		dp[0][0][0] = 1;
		for (int i = 0;i < n;i++) {
			int x = d[i];
			for (int j = 0;j < n;j++) {
				for (int k = 0;k < 2500;k++) {
					if (dp[i][j][k]>0) {
						dp[i+1][j][k] += dp[i][j][k];
						dp[i+1][j+1][k+x] += dp[i][j][k];
					}
				}
			}
		}

		long ret = 0;

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= 2500;j++) {
				if (i*a==j&&dp[n][i][j]>0) {
					ret += dp[n][i][j];
				}
			}
		}

		System.out.println(ret);
	}
}