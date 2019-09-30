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

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		long id = nextLong();
		long t[] = new long[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextLong();
		}
		long l = 0;
		long r = t[0] * id;
		while (l < r) {
			long mid = (l + r) >>> 1;
			long cnt = 0;
			for (int i = 0; i < n; i++) {
				cnt += mid / t[i] + 1;
			}
			if (cnt >= id) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		for (int i = 0; i < n; i++) {
			id -= (l + t[i] - 1) / t[i];
		}
		for (int i = 0; i < n; i++) {
			if (l % t[i] == 0) {
				if (--id == 0) {
					printCase();
					out.println(i + 1);
					return;
				}
			}
		}
		throw new AssertionError();
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