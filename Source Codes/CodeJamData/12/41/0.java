import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
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
		int x[] = new int[n];
		int l[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			l[i] = nextInt();
		}
		int w = nextInt();
		int dist[] = new int[n];
		dist[0] = x[0];
		boolean processed[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			int max = -1;
			for (int j = 0; j < n; j++) {
				if (!processed[j] && (max < 0 || dist[max] < dist[j])) {
					max = j;
				}
			}
			processed[max] = true;
			for (int j = 0; j < n; j++) {
				if (processed[j]) {
					continue;
				}
				int cd = abs(x[max] - x[j]);
				if (cd <= dist[max] && dist[j] < min(cd, l[j])) {
					dist[j] = min(cd, l[j]);
				}
			}
		}
		printCase();
		for (int i = 0; i < n; i++) {
			if (dist[i] + x[i] >= w) {
				out.println("YES");
				return;
			}
		}
		out.println("NO");
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