import java.util.*;
import java.lang.*;

public class Main {
	static long mod = 1000000007;
	static int h;
	static int w;
	static int k;
	static long[][] dp;
	static int i;
	static int j;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		k = sc.nextInt();
		dp = new long[h + 1][w + 2];
		dp[0][1] = 1;
		for (i = 1; i <= h; i++) {
			for (j = 1; j <= w; j++) {
				dfs(1, false, false, false);
			}
		}
		System.out.println(dp[h][k]);
	}
	static void dfs(int now, boolean te, boolean mae, boolean ato) {
		if (now == w) {
			if (mae) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= mod;
			} else if (ato) {
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			} else {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= mod;
			}
			return;
		}
		if (te) {
			dfs(now + 1, false, mae, ato);
		} else if (now == j - 1) {
			dfs(now + 1, true, true, false);
			dfs(now + 1, false, mae, ato);
		} else if (now == j) {
			dfs(now + 1, true, mae, true);
			dfs(now + 1, false, mae, ato);
		} else {
			dfs(now + 1, true, mae, ato);
			dfs(now + 1, false, mae, ato);
		}

	}
}