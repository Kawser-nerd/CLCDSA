import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import java.math.*;
import java.util.*;

public class A {
	boolean TIME = true;
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt(), m = sc.nextInt();
		int[][] is = new int[m][];
		List<Integer> list = new ArrayList<Integer>();
		list.add(0);
		list.add(n);
		for (int i = 0; i < m; i++) {
			int k = sc.nextInt();
			is[i] = new int[k + 1];
			is[i][k] = n;
			for (int j = 1; j < k; j++) is[i][j] = sc.nextInt() - 1;
			for (int j = 1; j < k; j++) if (is[i][j] < n) list.add(is[i][j]);
		}
		Collections.sort(list);
		int N = list.size();
		BigInteger res = ZERO;
		for (int i = 0; i < N - 1; i++) {
			int s = list.get(i), t = list.get(i + 1);
			if (s < t) {
//				debug("st", s, t);
				BigInteger[] dp = new BigInteger[m + 1];
				fill(dp, ZERO);
				dp[0] = ONE;
				for (int j = 0; j < m; j++) {
					int num = lowerBound(is[j], t);
//					for (int k : is[j]) if (k < t) num++;
//					debug(j, num);
					BigInteger a = valueOf(num);
					BigInteger b = valueOf(n - num);
					for (int k = m; k > 0; k--) {
						dp[k] = dp[k].multiply(b).add(dp[k - 1].multiply(a));
					}
					dp[0] = dp[0].multiply(b);
				}
				BigInteger tmp = ZERO;
//				debug("dp", dp);
				for (int j = 0; j <= m; j++) {
					BigInteger a = valueOf(j);
					a = a.multiply(a);
					tmp = tmp.add(a.multiply(dp[j]));
				}
//				debug(tmp);
				res = res.add(tmp.multiply(valueOf(t - s)));
			}
		}
//		debug("res", res);
		BigInteger div = valueOf(n).pow(m);
		BigInteger gcd = res.gcd(div);
		res = res.divide(gcd);
		div = div.divide(gcd);
		System.out.printf("%d+%d/%d%n", res.divide(div), res.mod(div), div);
	}
	
	int lowerBound(int[] is, int v) {
		int s = -1, t = is.length;
		while (t - s > 1) {
			int m = (s + t) >>> 1;
			if (is[m] >= v) t = m;
			else s = m;
		}
		return t;
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
