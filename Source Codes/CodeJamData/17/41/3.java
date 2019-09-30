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
import java.util.StringTokenizer;

public class A {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static int get(int cnts[], int i, int v) {
		int add = cnts[i] / v;
		cnts[i] -= add * v;
		return add;
	}

	static int get(int cnts[], int i, int v, int j, int w) {
		int add = min(cnts[i] / v, cnts[j] / w);
		cnts[i] -= add * v;
		cnts[j] -= add * w;
		return add;
	}

	static void solve() throws Exception {
		int n = nextInt();
		int p = nextInt();
		int cnts[] = new int[p];
		for (int i = 0; i < n; i++) {
			++cnts[nextInt() % p];
		}
		int ans = cnts[0];
		switch (p) {
		case 2:
			ans += get(cnts, 1, 2);
			break;
		case 3:
			ans += get(cnts, 1, 1, 2, 1);
			ans += get(cnts, 1, 3);
			ans += get(cnts, 2, 3);
			break;
		case 4:
			ans += get(cnts, 1, 1, 3, 1);
			ans += get(cnts, 2, 2);
			ans += get(cnts, 2, 1, 1, 2);
			ans += get(cnts, 2, 1, 3, 2);
			ans += get(cnts, 1, 4);
			ans += get(cnts, 3, 4);
			break;
		default:
			throw new AssertionError();
		}
		for (int i = 1; i < p; i++) {
			if (cnts[i] != 0) {
				++ans;
				break;
			}
		}
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