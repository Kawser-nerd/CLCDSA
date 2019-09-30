import java.util.*;

public class Main {
	static final long MOD = 1000000007L;
	static long[][] dp;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		if (n > k) {
			dp =  new long[n + k][k + 1];
			System.out.println(combination(n + k - 1, k));
		} else {
			dp =  new long[n + 1][k % n + 1];
			System.out.println(combination(n, k % n));
		}
	}
	
	static long combination(int left, int right) {
		if (right > left - right) {
			return combination(left, left - right);
		}
		if (right == 0) {
			return 1;
		}
		if (right == 1) {
			return left;
		}
		if (dp[left][right] != 0) {
			return dp[left][right];
		}
		long val = combination(left - 1, right) + combination(left - 1, right - 1);
		val %= MOD;
		dp[left][right] = val;
		return val;
	}
}