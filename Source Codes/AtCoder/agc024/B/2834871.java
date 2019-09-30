import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		int max = -1;
		int[] dp = new int[n+1];
		for (int i = 0; i < n; i++) {
			dp[a[i]] = dp[a[i]-1] + 1;
			max = Math.max(max, dp[a[i]]);
		}

		System.out.println(n - max);

	}
}