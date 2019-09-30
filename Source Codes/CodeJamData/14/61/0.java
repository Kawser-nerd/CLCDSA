import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		boolean m[][] = new boolean[2 * n][2 * n];
		for (int i = 0; i < 2 * n; i++) {
			String l = next();
			for (int j = 0; j < 2 * n; j++) {
				m[i][j] = l.charAt(j) == '1';
			}
		}
		boolean h[] = m[0];
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (h[i]) {
				++cnt;
			}
		}
		if (cnt != n) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		boolean ih[] = new boolean[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			ih[i] = !h[i];
		}
		boolean v[] = new boolean[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			if (Arrays.equals(h, m[i])) {
				v[i] = false;
			} else if (Arrays.equals(ih, m[i])) {
				v[i] = true;
			} else {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
		}
		cnt = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (v[i]) {
				++cnt;
			}
		}
		if (cnt != n) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (h[i] != (i % 2 == 0)) {
				++cnt1;
			}
			if (v[i] != (i % 2 == 0)) {
				++cnt2;
			}
		}
		printCase();
		out.println((min(cnt1, 2 * n - cnt1) + min(cnt2, 2 * n - cnt2)) / 2);
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