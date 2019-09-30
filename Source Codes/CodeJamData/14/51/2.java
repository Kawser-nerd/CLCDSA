import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		long p = nextLong();
		long q = nextLong();
		long r = nextLong();
		long s = nextLong();
		long a[] = new long[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = a[i - 1] + ((i - 1) * p + q) % r + s;
		}
		long dyn2[] = new long[n + 1];
		for (int i = 1, j = 0; i <= n; i++) {
			while (j < i && a[j + 1] < a[i] - a[j + 1]) {
				++j;
			}
			dyn2[i] = max(a[j], a[i] - a[j]);
			if (j < i) {
				dyn2[i] = min(dyn2[i], max(a[j + 1], a[i] - a[j + 1]));
			}
		}
		long dyn3[] = new long[n + 1];
		for (int i = 1, j = 0; i <= n; i++) {
			while (j < i && dyn2[j + 1] < a[i] - a[j + 1]) {
				++j;
			}
			dyn3[i] = max(dyn2[j], a[i] - a[j]);
			if (j < i) {
				dyn3[i] = min(dyn3[i], max(dyn2[j + 1], a[i] - a[j + 1]));
			}
		}
		printCase();
		out.println(1 - (double) dyn3[n] / a[n]);
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