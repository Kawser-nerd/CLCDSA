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

public class A {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void solve() throws Exception {
		int n = nextInt();
		int r = nextInt();
		int p = nextInt();
		int s = nextInt();
		String sr = "R";
		String sp = "P";
		String ss = "S";
		for (int i = 0; i < n; i++) {
			int nn = 1 << (n - i - 1);
			if (r > nn || p > nn || s > nn) {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
			int t = nn - p;
			p = nn - s;
			s = nn - r;
			r = t;
			String st = sr.compareTo(ss) > 0 ? ss + sr : sr + ss;
			ss = ss.compareTo(sp) > 0 ? sp + ss : ss + sp;
			sp = sp.compareTo(sr) > 0 ? sr + sp : sp + sr;
			sr = st;
		}
		printCase();
		out.println(r > 0 ? sr : p > 0 ? sp : ss);
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