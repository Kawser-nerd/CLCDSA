import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static final int MOD = 1000000007;
	
	static final int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}

	static final int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static void solve() throws Exception {
		int r = nextInt();
		int c = nextInt();
		int ans1s[] = new int[r + 1];
		int ans2s[] = new int[r + 1];
		int ans1u3[] = new int[r + 1];
		int ans2u3[] = new int[r + 1];
		int ans1u4[] = new int[r + 1];
		int ans2u4[] = new int[r + 1];
		int ans1u6[] = new int[r + 1];
		int ans2u6[] = new int[r + 1];
		int ans1u12[] = new int[r + 1];
		int ans2u12[] = new int[r + 1];
		ans1s[0] = 1;
		ans2s[0] = 1;
		for (int i = 1; i <= r; i++) {
			ans2s[i] = i >= 2 ? ans1s[i - 2] : 0;
			ans2u3[i] = i >= 2 ? ans1u3[i - 2] : 0;
			ans2u4[i] = i >= 2 ? ans1u4[i - 2] : 0;
			ans2u6[i] = i >= 2 ? ans1u6[i - 2] : 0;
			ans2u12[i] = i >= 2 ? ans1u12[i - 2] : 0;
			ans1s[i] = ans2s[i - 1];
			ans1u3[i] = ans2u3[i - 1];
			ans1u4[i] = ans2u4[i - 1];
			ans1u6[i] = ans2u6[i - 1];
			ans1u12[i] = ans2u12[i - 1];
			if (i >= 2 && c % 3 == 0) {
				ans1u3[i] = add(ans1u3[i], ans2s[i - 2]);
				ans1u3[i] = add(ans1u3[i], mul(ans2u3[i - 2], 3));
				ans1u12[i] = add(ans1u12[i], ans2u4[i - 2]);
				ans1u6[i] = add(ans1u6[i], mul(ans2u6[i - 2], 3));
				ans1u12[i] = add(ans1u12[i], mul(ans2u12[i - 2], 3));
			}
			if (i >= 2 && c % 6 == 0) {
				ans1u6[i] = add(ans1u6[i], ans2s[i - 2]);
				ans1u6[i] = add(ans1u6[i], mul(ans2u3[i - 2], 3));
				ans1u12[i] = add(ans1u12[i], mul(ans2u4[i - 2], 2));
				ans1u6[i] = add(ans1u6[i], mul(ans2u6[i - 2], 6));
				ans1u12[i] = add(ans1u12[i], mul(ans2u12[i - 2], 6));
			}
			if (i >= 3 && c % 4 == 0) {
				ans1u4[i] = add(ans1u4[i], ans2s[i - 3]);
				ans1u12[i] = add(ans1u12[i], ans2u3[i - 3]);
				ans1u4[i] = add(ans1u4[i], mul(ans2u4[i - 3], 4));
				ans1u12[i] = add(ans1u12[i], mul(ans2u6[i - 3], 2));
				ans1u12[i] = add(ans1u12[i], mul(ans2u12[i - 3], 4));
			}
		}
		int ans = 0;
		ans = add(ans, ans1s[r]);
		ans = add(ans, ans1u3[r]);
		ans = add(ans, ans1u4[r]);
		ans = add(ans, ans1u6[r]);
		ans = add(ans, ans1u12[r]);
		ans = add(ans, ans2s[r]);
		ans = add(ans, ans2u3[r]);
		ans = add(ans, ans2u4[r]);
		ans = add(ans, ans2u6[r]);
		ans = add(ans, ans2u12[r]);
		printCase();
		out.println(ans);
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}