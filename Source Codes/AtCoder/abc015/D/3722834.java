import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int W = sc.nextInt();
		int N = sc.nextInt();
		int K = sc.nextInt();
		int A[] = new int[N];
		int B[] = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		int dp[][][] = new int[N + 1][W + 1][K + 1];
		
		for(int i = 0; i < N + 1; i++) {
			for(int j = 0; j < W + 1; j++) {
				Arrays.fill(dp[i][j], 0);
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 1; j <= W; j++) {
				for(int k = 1; k <= K; k++) {
					if(j - A[i] >= 0) {
						dp[i + 1][j][k] = Math.max(dp[i][j - A[i]][k - 1] + B[i], dp[i][j][k]);
					} else {
						dp[i + 1][j][k] = dp[i][j][k];
					}
				}
			}
		}
		
		System.out.println(dp[N][W][K]);
	}
}