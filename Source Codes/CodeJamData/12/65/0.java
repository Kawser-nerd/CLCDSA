import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		// SMALL TEST ONLY
		int n = nextInt() - 1;
		int l[] = new int[n];
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = nextInt() - 1;
			r[i] = nextInt() - 1;
		}
		Set<Integer> states = new HashSet<Integer>();
		int cur = 0;
		int mask = 0;
		int ans = 1;
//		System.err.println("===");
		while (true) {
			if (!states.add((cur << n) | mask)) {
				printCase();
				out.println("Infinity");
				return;
			}
			int next = (((mask & (1 << cur)) != 0) ? r : l)[cur];
			mask ^= 1 << cur;
			cur = next;
//			System.err.println("Go to " + (cur + 1));
			if (cur == n) {
				printCase();
				out.println(ans);
				return;
			}
			++ans;
		}
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