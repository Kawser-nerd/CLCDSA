import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Ma = sc.nextInt();
		int Mb = sc.nextInt();
		int a[] = new int[N];
		int b[] = new int[N];
		int c[] = new int[N];
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		int[][][] dp = new int[N + 1][500][500];
		for(int i = 0; i < N + 1; i++) {
			for(int j = 0; j < 499; j++) {
				for(int k = 0; k < 499; k++) {
					dp[i][j][k] = Integer.MAX_VALUE / 2;
				}
			}
		}
		dp[0][0][0] = 0;
		
		int ans = Integer.MAX_VALUE / 2;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 400; j++) {
				for(int k = 0; k < 400; k++) {
					//if(j + a[i] < 10 * N + 1 && k + b[i] < 10 * N + 1) {
						dp[i + 1][j + a[i]][k + b[i]] = Math.min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
						dp[i + 1][j][k] = Math.min(dp[i + 1][j][k], dp[i][j][k]);
					//}
				}
			}
		}
		
		for(int j = 1; j <= 400; j++) {
			for(int k = 1; k <= 400; k++) {
				if(k * Ma == j * Mb && dp[N][j][k] != Integer.MAX_VALUE) {
					ans = Math.min(ans, dp[N][j][k]);
				}
			}
		}
		
		if(ans == Integer.MAX_VALUE / 2) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}
}