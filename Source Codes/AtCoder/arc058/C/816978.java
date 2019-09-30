import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static final int MOD = 1_000_000_007;

	public static void main(String[] args) {
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int Z = sc.nextInt();
		long[] p10 = new long[N + 1];
		p10[0] = 1;
		for (int i = 0; i < N; ++i) {
			p10[i + 1] = p10[i] * 10 % MOD;
		}
		long[][] dp = new long[N + 1][1 << (X + Y + Z)];
		dp[0][1] = 1;
		long ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < (1 << (X + Y + Z)); ++j) {
				if (dp[i][j] == 0) continue;
				for (int k = 1; k <= 10; ++k) {
					if (k <= Z && (j & (1 << (X + Y + Z - k))) != 0) {
						ans += (dp[i][j] * p10[N - i - 1]) % MOD;
						continue;
					}
					int next = 1;
					for (int l = 0; k + l <= X; ++l) {
						if ((j & (1 << l)) == 0) continue;
						next |= 1 << (k + l);
					}
					for (int l = X; k + l <= X + Y; ++l) {
						if ((j & (1 << l)) == 0) continue;
						next |= 1 << (k + l);
					}
					for (int l = X + Y; k + l < X + Y + Z; ++l) {
						if ((j & (1 << l)) == 0) continue;
						next |= 1 << (k + l);
					}

					dp[i + 1][next] += dp[i][j];
					if (dp[i + 1][next] >= MOD) dp[i + 1][next] -= MOD;
				}
			}
		}
		System.out.println(ans % MOD);
	}
}