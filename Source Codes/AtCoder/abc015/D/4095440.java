import java.util.*;

public class Main {
	static int[] a;
	static int[] b;
	static int[][][] dp;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();
		a = new int[n];
		b = new int[n];
		dp = new int[w + 1][k + 1][n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		System.out.println(dfs(w, k, n - 1));
	}
	
	static int dfs(int w, int k, int x) {
		if (x < 0) {
			return 0;
		}
		if (dp[w][k][x] != 0) {
			return dp[w][k][x];
		}
		int aa = dfs(w, k, x - 1);
		int bb = 0;
		if (w - a[x] >= 0 && k - 1 >= 0) {
			bb = dfs(w - a[x], k - 1, x - 1) + b[x];
		}
		dp[w][k][x] = Math.max(aa, bb);
		return dp[w][k][x];
	}
}