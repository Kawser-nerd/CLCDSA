import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Ma = sc.nextInt();
		int Mb = sc.nextInt();
		int[] a = new int[N];
		int[] b = new int[N];
		int[] c = new int[N];
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		sc.close();
		int n = 401;

		int[][][] dp = new int[N + 1][n][n];
		int INF = 100000000;
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					dp[i][j][k] = INF;
				}
			}
		}
		dp[0][0][0] = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					if(dp[i][j][k] != INF) {
						int A = j + a[i];
						int B = k + b[i];
						dp[i + 1][j][k] = Math.min(dp[i + 1][j][k], dp[i][j][k]);
						dp[i + 1][A][B] = Math.min(dp[i + 1][A][B], dp[i][j][k] + c[i]);
					}
				}
			}
		}
		int min = INF;
		for(int j = 1; j < n; j++) {
			for(int k = 1; k < n; k++) {
				if(Ma * k == Mb * j) {
					min = Math.min(min, dp[N][j][k]);
				}
			}
		}
//		for(int j = 1; j < 11; j++) {
//			for(int k = 1; k < 11; k++) {
//				if(dp[N][j][k] != INF) {
//					System.out.print(dp[N][j][k] + " ");
//				}else {
//					System.out.print("0 ");
//				}
//			}
//			System.out.println();
//		}
		if(min == INF) min = -1;
		System.out.println(min);
	}
}