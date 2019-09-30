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
import java.util.Locale;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void solve() throws Exception {
		int n = nextInt();
		int q = nextInt();
		int e[] = new int[n];
		int s[] = new int[n];
		for (int i = 0; i < n; i++) {
			e[i] = nextInt();
			s[i] = nextInt();
		}
		long d[][] = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cd = nextInt();
				d[i][j] = cd < 0 ? Long.MAX_VALUE : cd;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					long a = d[j][i], b = d[i][k];
					if (a != Long.MAX_VALUE && b != Long.MAX_VALUE) {
						d[j][k] = min(d[j][k], a + b);
					}
				}
			}
		}
		double t[][] = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				long cd = d[i][j];
				t[i][j] = cd > e[i] ? Double.POSITIVE_INFINITY : (double) cd / s[i];
			}
			t[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					t[j][k] = min(t[j][k], t[j][i] + t[i][k]);
				}
			}
		}
		printCase();
		for (int i = 0; i < q; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			if (i > 0) {
				out.print(' ');
			}
			double ct = t[u][v];
			if (ct == Double.POSITIVE_INFINITY) {
				throw new AssertionError();
			}
			out.printf(Locale.US, "%.9f", ct);
		}
		out.println();
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