import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		long[] dp = new long[n];
		dp[0] = 0;
		dp[1] = Math.abs(a[1] - a[0]);
		for (int i = 2; i < n; i++) {
			long n1 = dp[i - 1] + Math.abs(a[i] - a[i - 1]);
			long n2 = dp[i - 2] + Math.abs(a[i] - a[i - 2]);
			dp[i] = Math.min(n1, n2);
		}
		System.out.println(dp[n - 1]);
	}
}