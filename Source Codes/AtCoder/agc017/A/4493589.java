import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int P = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		int max = N * 100;
		long[][] dp = new long[N + 1][max + 1];
		dp[0][0] = 1;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < max; j++) {
				if(dp[i][j] != 0) {
					dp[i + 1][j] += dp[i][j];
					int k = j + A[i];
					dp[i + 1][k] += dp[i][j];
				}
			}
		}
		long cnt = 0;
		for(int i = 0; i <= max; i++) {
			if(i % 2 == P) {
				cnt += dp[N][i];
			}
		}
		System.out.println(cnt);
	}
}