import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	boolean TIME = false;
	Scanner sc;
	
	int D, I, M, N;
	int[] a;
	
	void solve() {
		D = sc.nextInt();
		I = sc.nextInt();
		M = sc.nextInt();
		N = sc.nextInt();
		a = new int[N];
		for (int i = 0; i < N; i++) a[i] = sc.nextInt();
		long[][] dp = new long[N + 1][256];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 256; j++) {
				long tmp = dp[i][j] + D;
				if (M == 0) {
					tmp = min(tmp, dp[i][j] + abs(a[i] - j));
				} else {
					for (int k = 0; k < 256; k++) {
						long diff = abs(k - j);
						long need = (diff - 1) / M;
						if (need < 0) need = 0;
						long cost = need * I + abs(a[i] - j);
						if (tmp > dp[i][k] + cost) {
							tmp = dp[i][k] + cost;
						}
					}
				}
				dp[i + 1][j] = tmp;
			}
		}
		long res = Long.MAX_VALUE;
		for (int i = 0; i < 256; i++) res = min(res, dp[N][i]);
		System.out.println(res);
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
		new B().run();
	}
}
