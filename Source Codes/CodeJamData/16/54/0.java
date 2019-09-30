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

	static void solve() throws Exception {
		int n = nextInt();
		int l = nextInt();
		String good[] = new String[n];
		for (int i = 0; i < n; i++) {
			good[i] = next();
		}
		String bad = next();
		for (int i = 0; i < n; i++) {
			if (bad.equals(good[i])) {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
		}
		printCase();
		if (l == 1) {
			out.println(inv(bad.charAt(0)) + "? " + inv(bad.charAt(0)));
			return;
		}
		for (int i = 0; i < l; i++) {
			out.print(inv(bad.charAt(i)));
			out.print('?');
		}
		out.print(' ');
		for (int i = 0; i < l - 1; i++) {
			if (bad.charAt(i) == bad.charAt(i + 1)) {
				out.print(bad.charAt(i));
			} else {
				out.print(bad.charAt(i + 1));
				out.print(bad.charAt(i));
			}
		}
		out.println();
	}

	static char inv(char c) {
		return c == '0' ? '1' : '0';
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