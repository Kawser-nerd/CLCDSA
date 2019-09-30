import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int x = nextInt();
		int y = nextInt();
		int sum = abs(x) + abs(y);
		int ans = 0;
		int csum = 0;
		while (csum < sum || ((csum ^ sum) & 1) != 0) {
			++ans;
			csum += ans;
		}
		StringBuilder sb = new StringBuilder();
		for (int shift = ans; shift > 0; shift--) {
			if (abs(y) > abs(x)) {
				if (y > 0) {
					sb.append('N');
					y -= shift;
				} else {
					sb.append('S');
					y += shift;
				}
			} else {
				if (x > 0) {
					sb.append('E');
					x -= shift;
				} else {
					sb.append('W');
					x += shift;
				}
			}
		}
		if (x != 0 || y != 0) {
			throw new AssertionError();
		}
		sb.reverse();
		printCase();
		out.println(sb.toString());
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