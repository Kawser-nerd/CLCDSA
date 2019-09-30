import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			int[][] g = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					g[i][j] = sc.nextInt();
				}
			}
			int n2 = n / 2;
			int[][][] dp = new int[m + 1][1 << n][1 << n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < 1 << n; j++) {
					fill(dp[i][j], -INF);
				}
			}
			for (int i = 0; i < 1 << n; i++) {
				dp[0][0][i] = i >> n2 & 1;
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < 1 << n; j++) {
					for (int k = 0; k < 1 << n; k++) {
						for (int h = 0; h < 1 << n; h++) {
							boolean ok = true;
							for (int a = 0; a < n && ok; a++) {
								int c = 0;
								for (int d = max(a - 1, 0); d < n && d <= a + 1; d++) {
									c += j >> d & 1;
									c += k >> d & 1;
									c += h >> d & 1;
								}
								if (c != g[a][i]) ok = false;
							}
							if (ok) {
								dp[i + 1][k][h] = max(dp[i + 1][k][h], dp[i][j][k] + (h >> n2 & 1));
							}
						}
					}
				}
			}
			int max = 0;
			for (int i = 0; i < 1 << n; i++) max = max(max, dp[m][i][0]);
			System.out.println(max);
		}
	}
	
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
