import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class E {
	public static void main(String[] args) {
		new E().run();
	}
	
	int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
//			debug(o, on);
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			int[] as = new int[max(n, m) + 1], bs = new int[max(n, m) + 1];
			for (int i = 1; i <= n; i++) {
				char[] cs = sc.next().toCharArray();
				for (int j = 0; j < m; j++) {
					if (cs[j] == '#') {
						if (n < m) as[1 + j] |= 1 << (i - 1);
						else as[i] |= 1 << j;
					}
					if (cs[j] == '?') {
						if (n < m) bs[1 + j] |= 1 << (i - 1);
						else bs[i] |= 1 << j;
					}
				}
			}
			if (n < m) {
				int t = n;
				n = m;
				m = t;
			}
			int[] count = new int[1 << m];
			boolean[] ok = new boolean[1 << m];
			for (int i = 0; i < 1 << m; i++) {
				count[i] = Integer.bitCount(i) * 4;
				ok[i] = true;
				for (int j = 0; j < m; j++) if ((i & 1 << j) != 0) {
					if (j > 0 && (i & 1 << (j - 1)) != 0) count[i]--;
					if (j + 1 < m && (i & 1 << (j + 1)) != 0) count[i]--;
					if (j > 0 && (i & 1 << (j - 1)) != 0 && j + 1 < m && (i & 1 << (j + 1)) != 0) ok[i] = false;
				}
			}
			int[] count2 = new int[1 << m];
			for (int i = 0; i < 1 << m; i++) count2[i] = Integer.bitCount(i) * 2;
			int[][] dp = new int[n + 1][1 << m];
			for (int i = 0; i <= n; i++) fill(dp[i], -INF);
			dp[0][0] = 0;
			for (int i = 0; i < n; i++) {
				int sup = bs[i];
				int sub = sup;
				do {
					if (ok[sub]) {
						int sup2 = bs[i + 1];
						int sub2 = sup2;
						do {
							int tmp = dp[i][sub] + count[as[i + 1] | sub2] - count2[(as[i] | sub) & (as[i + 1] | sub2)];
							if (dp[i + 1][sub2] < tmp) dp[i + 1][sub2] = tmp;
							sub2 = (sub2 - 1) & sup2;
						} while (sub2 != sup2);
					}
					sub = (sub - 1) & sup;
				} while (sub != sup);
			}
			int max = 0;
			for (int i : dp[n]) max = max(max, i);
			System.out.println(max);
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
