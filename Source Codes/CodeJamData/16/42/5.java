import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N, K;
	double[] ps;
	
	void read() {
		N = sc.nextInt();
		K = sc.nextInt();
		ps = new double[N];
		for (int i = 0; i < N; i++) ps[i] = sc.nextDouble();
		sort(ps);
	}
	
	double f(double[] ps) {
		int n = ps.length;
		double[][] dp = new double[n + 1][n + 1];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j + 1 <= n) dp[i + 1][j + 1] += dp[i][j] * ps[i];
				dp[i + 1][j] += dp[i][j] * (1 - ps[i]);
			}
		}
		return dp[n][n / 2];
	}
	
	void solve() {
		double res = 0;
		for (int i = 0; i <= K; i++) {
			double[] qs = new double[K];
			for (int j = 0; j < i; j++) qs[j] = ps[j];
			for (int j = 0; j < K - i; j++) qs[i + j] = ps[N - 1 - j];
			res = max(res, f(qs));
		}
		System.out.printf("%.10f%n", res);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
