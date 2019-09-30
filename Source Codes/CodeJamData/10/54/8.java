import java.io.*;
import java.util.*;

public class D {
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	final static int mod = 1000000007;
	int[][] a;
	int[][] a0;
	int b, s1;
	static int[][] cnk;
	static int[] fact;
	long[] bp = new long[101];

	private void solve() {
		long s = in.nextLong();
		b = in.nextInt();
		
		bp[0] = 1;
		for (int i = 1; i < 101; i++) {
			bp[i] = bp[i - 1] * b;
		}
		s1 = b * (b - 1) / 2;
		int len = 0;
		long ss = s;
		while (ss > 0) {
			len++;
			ss /= b;
		}
		int[][][] aa = new int[b + 1][s1 + 1][b + 1];
		int[][][] aa0 = new int[b + 1][s1 + 1][b + 1];
		aa[0][0][0] = 1;
		aa0[0][0][0] = 1;
		for (int i = 0; i < b; i++) {
			for (int t = 0; t <= s1; t++) {
				for (int k = 0; k <= b; k++) {
					if (aa[i][t][k] > 0) {
						aa[i + 1][t + i][k + 1] = (aa[i + 1][t + i][k + 1] + aa[i][t][k]) % mod;
					}
					if (aa0[i][t][k] > 0 && i > 0) {
						aa0[i + 1][t + i][k + 1] = (aa0[i + 1][t + i][k + 1] + aa0[i][t][k]) % mod;
					}
					aa[i + 1][t][k] = (aa[i + 1][t][k] + aa[i][t][k]) % mod;
					aa0[i + 1][t][k] = (aa0[i + 1][t][k] + aa0[i][t][k]) % mod;
				}
			}
		}
		a = aa[b];
		a0 = aa0[b];
		int ans = 0;
		
//		System.out.println(solve(3, 1, 0, s));
		for (int i = 1; i <= len; i++) {
			for (int n = 1; n <= b; n++) {
				ans = (ans + solve(i, n, 0, s)) % mod;
			}
		}
		out.println(ans);
	}
	
	int solve(int wid, int n, int ns, long sum) {
		if (wid == 0) {
			if (ns != n) {
				return 0;
			}
			if (sum != 0) {
				return 0;
			}
			return 1;
		}
		int ans = 0;
		for (int m = Math.max(ns, 1); m <= n; m++) {
			for (int s = 0; s <= s1; s++) {
				long sum2 = sum - s * bp[wid - 1];
				if (sum2 < 0) {
					break;
				}
				int bez0 = a0[s][m];
				int s0 = (a[s][m] + mod - a0[s][m]) % mod;
				int sol = solve(wid - 1, n, m, sum2);
				if (sol == 0) {
					continue;
				}
				long cur = cnk[m][ns];
				cur = cur * bez0 % mod;
				cur = cur * sol % mod;
				cur = (cur * fact[ns]) % mod;
				ans = (ans + (int) cur) % mod;
				if (ns > 0) {
					cur = cnk[m - 1][ns - 1];
					cur = cur * s0 % mod;
					cur = cur * sol % mod;
					cur = (cur * fact[ns]) % mod;
					ans = (ans + (int) cur) % mod;
				}
			}
		}
//		System.out.println(wid + " " + n + " " + ns + " " + sum + "    " + ans);
		return ans;
	}

	public static void main(String[] args) throws IOException {
		cnk = new int[101][101];
		fact = new int[101];
		for (int i = 0; i < 101; i++) {
			fact[i] = (i == 0) ? 1 : (int) ((fact[i - 1] * (long) i) % mod);
			cnk[i][0] = 1;
			cnk[i][i] = 1;
			for (int j = 1; j < i; j++) {
				cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
			}
		}
		
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new D().solve();
		}
		in.close();
		out.close();
	}
}
