import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int R, N, M, K;
	long[] ps;
	
	void read() {
		R = sc.nextInt();
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		ps = new long[K];
		Random rand = new Random();
		int ok = 0;
		for (int rep = 0; rep < R; rep++) {
			for (int i = 0; i < K; i++) {
				ps[i] = sc.nextLong();
			}
//			long[] ans = new long[N];
//			for (int i = 0; i < N; i++) ans[i] = 2 + rand.nextInt(M - 1);
//			sort(ans);
//			for (int i = 0; i < K; i++) {
//				ps[i] = 1;
//				for (int j = 0; j < N; j++) if (rand.nextBoolean()) ps[i] *= ans[j];
//			}
			long[] res = solve();
//			sort(res);
//			if (Arrays.equals(ans, res)) ok++;
//			debug(ok, rep);
//			debug(ans);
//			debug(res);
//			debug();
			for (int i = 0; i < N; i++) System.out.print(res[i]);
			System.out.println();
		}
	}
	
	long gcd(long x, long y) {
		long t;
		while (y != 0) {
			t = x % y; x = y; y = t;
		}
		return abs(x);
	}
	
	long lcm(long[] vs) {
		long lcm = 1;
		for (int i = 0; i < vs.length; i++) lcm = lcm * vs[i] / gcd(lcm, vs[i]);
		return lcm;
	}
	
	long[][] C = new long[50 + 1][50 + 1];
	{
		C[0][0] = 1;
		for (int i = 1; i <= 50; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= 50; j++) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
			}
		}
	}
	
	int N2, N3;
	int[] n2, n3, n5, n7;
	long[] res;
	double max;
	
	void rec(long[] vs, int i, int v) {
		if (i == N) {
			double[][] dp = new double[N2 + 1][N3 + 1];
			dp[0][0] = 1;
			int m5 = 0, m7 = 0;
			for (int j = 0; j < N; j++) {
				if (vs[j] == 5) {
					m5++;
				} else if (vs[j] == 7) {
					m7++;
				} else {
					int m2 = (vs[j] == 2 ? 1 : vs[j] == 4 ? 2 : vs[j] == 6 ? 1 : vs[j] == 8 ? 3 : 0), m3 = (vs[j] == 3 ? 1 : vs[j] == 6 ? 1 : 0);
					for (int i2 = N2 - m2; i2 >= 0; i2--) {
						for (int i3 = N3 - m3; i3 >= 0; i3--) {
							dp[i2 + m2][i3 + m3] += dp[i2][i3];
						}
					}
				}
			}
			double prod = 1;
			for (int j = 0; j < K; j++) {
				prod *= dp[n2[j]][n3[j]] * C[m5][n5[j]] * C[m7][n7[j]];
			}
			int n = N;
			for (int j = 2; j <= M; j++) {
				int m = 0;
				for (int k = 0; k < N; k++) if (vs[k] == j) m++;
				prod *= C[n][m];
				n -= m;
			}
			if (max < prod) {
				max = prod;
				res = vs.clone();
			}
		} else {
			vs[i] = v;
			rec(vs, i + 1, v);
			if (v < M) rec(vs, i, v + 1);
		}
	}
	
	long[] solve() {
		N2 = N3 = 0;
		n2 = new int[K];
		n3 = new int[K];
		n5 = new int[K];
		n7 = new int[K];
		for (int i = 0; i < K; i++) {
			long v = ps[i];
			while (v % 2 == 0) {
				n2[i]++;
				v /= 2;
			}
			N2 = max(N2, n2[i]);
			while (v % 3 == 0) {
				n3[i]++;
				v /= 3;
			}
			N3 = max(N3, n3[i]);
			while (v % 5 == 0) {
				n5[i]++;
				v /= 5;
			}
			while (v % 7 == 0) {
				n7[i]++;
				v /= 7;
			}
		}
		res = new long[N];
		fill(res, 2);
		max = 0;
		rec(new long[N], 0, 2);
		debug(max);
		return res;
	}
	
	long[] solve2() {
		long lcm = lcm(ps), L = lcm;
		long[] res = new long[N];
		int n = 0;
		while (L % 5 == 0) {
			res[n++] = 5;
			L /= 5;
		}
		while (L % 7 == 0) {
			res[n++] = 7;
			L /= 7;
		}
		Random rand = new Random();
		fill(res, 2);
		double max = 0;
		for (int rep = 0; rep < 5000; rep++) {
			long[] vs = new long[N];
			for (int i = 0; i < n; i++) vs[i] = res[i];
			for (int i = n; i < N; i++) vs[i] = 2 + rand.nextInt(M - 1);
			if (lcm % lcm(vs) != 0) continue;
			double[] prob = new double[K];
			for (int i = 0; i < 1 << N; i++) {
				long prod = 1;
				for (int j = 0; j < N; j++) if ((i >> j & 1) != 0) {
					prod *= vs[j];
				}
				for (int j = 0; j < K; j++) if (ps[j] == prod) prob[j] += 1.0;
			}
			double prod = 1;
			for (int i = 0; i < K; i++) prod *= prob[i];
			if (max < prod) {
				max = prod;
				res = vs;
			}
		}
		debug(max);
		return res;
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d:%n", caseID);
			read();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
