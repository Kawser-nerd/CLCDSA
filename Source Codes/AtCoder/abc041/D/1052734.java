import java.util.Scanner;

public class Main {
	static int n, m;
	static int[][] gragh;
	static long[] dp;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		m = sc.nextInt();
		gragh = new int[n + 1][n + 1];
		dp = new long[(int) Math.pow(2, n)];

		for (int i = 0; i < m; i++) {
			gragh[sc.nextInt() - 1][sc.nextInt() - 1]++;
		}
		dp[0] = 1;

		for (int i = 1; i < dp.length; i++) {
			for (int j = 0; j < n; j++) {
				if (((i >> j) & 1) == 1) {
					int k;
					for (k = 0; k < n; k++) {
						if(((i >> k) & 1) == 1 && gragh[j][k] == 1){
							break;
						}
					}
					if(k == n){
						dp[i] += dp[i-(1<<j)];
					}
				}
			}
		}

		System.out.println(dp[dp.length-1]);
	}
}