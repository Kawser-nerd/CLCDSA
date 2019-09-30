import java.util.*;
import java.lang.*;

public class Main {
	static int n;
	static int[] a;
	static int[] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = sc.nextInt();
		}
		dp = new int[n + 1];
		dp[2] = Math.abs(a[2] - a[1]);
		dp(3);
		System.out.println(dp[n]);
	}
	static void dp(int k) {
		if (k > n) {
			return;
		} else {
			dp[k] = Math.min(Math.abs(a[k] - a[k - 2]) + dp[k - 2], Math.abs(a[k] - a[k - 1]) + dp[k - 1]);
		}
		dp(k + 1);
	}
}