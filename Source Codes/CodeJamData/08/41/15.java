import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	static final int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int m = sc.nextInt(), v = sc.nextInt();
			int[][] dp = new int[m][2];
			int[] g = new int[m];
			boolean[] can = new boolean[m];
			for (int i = 0; i < (m - 1) / 2; i++) {
				g[i] = sc.nextInt();
				can[i] = sc.nextInt() == 1;
				dp[i][0] = dp[i][1] = INF;
			}
			for (int i = (m - 1) / 2; i < m; i++) {
				int a = sc.nextInt();
				dp[i][a] = 0;
				dp[i][1 - a] = INF;
			}
			for (int i = (m - 1) / 2 - 1; i >= 0; i--) {
				int l = i * 2 + 1, r = i * 2 + 2;
				if (g[i] == 0) {
					for (int j = 0; j < 2; j++) {
						for (int k = 0; k < 2; k++) {
							dp[i][j|k] = min(dp[i][j|k], dp[l][j] + dp[r][k]);
						}
					}
				} else if (g[i] == 1) {
					for (int j = 0; j < 2; j++) {
						for (int k = 0; k < 2; k++) {
							dp[i][j&k] = min(dp[i][j&k], dp[l][j] + dp[r][k]);
						}
					}
				}
				if (can[i]) {
					if (g[i] == 0) {
						for (int j = 0; j < 2; j++) {
							for (int k = 0; k < 2; k++) {
								dp[i][j&k] = min(dp[i][j&k], dp[l][j] + dp[r][k] + 1);
							}
						}
					} else if (g[i] == 1) {
						for (int j = 0; j < 2; j++) {
							for (int k = 0; k < 2; k++) {
								dp[i][j|k] = min(dp[i][j|k], dp[l][j] + dp[r][k] + 1);
							}
						}
					}
				}
			}
			if (dp[0][v] == INF) System.out.println("IMPOSSIBLE");
			else System.out.println(dp[0][v]);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
