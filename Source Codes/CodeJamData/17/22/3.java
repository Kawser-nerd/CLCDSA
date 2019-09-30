import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
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
		int ns[] = new int[6];
		for (int i = 0; i < 6; i++) {
			ns[i] = nextInt();
		}
		for (int i = 0; i < 3; i++) {
			if (2 * ns[i] == n && 2 * ns[i + 3] == n) {
				printCase();
				for (int j = 0; j < n; j += 2) {
					out.print("ROYGBV".charAt(i));
					out.print("ROYGBV".charAt(i + 3));
				}
				out.println();
				return;
			}
		}
		int sum = 0, max = 0;
		for (int i = 0; i < 6; i += 2) {
			int val = ns[i] - ns[(i + 3) % 6];
			if (val < 0 || (val == 0 && ns[i] > 0)) {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
			sum += val;
			max = max(max, val);
		}
		if (2 * max > sum) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		int res[] = new int[n];
		int resPos = 0;
		int first = -1, last = -1;
		while (resPos < n) {
			int maxPos = -1, maxVal = -1;
			for (int i = 0; i < 6; i += 2) {
				if (i != last) {
					int val = ns[i] - ns[(i + 3) % 6];
					if (val > maxVal || (val == maxVal && i == first)) {
						maxVal = val;
						maxPos = i;
					}
				}
			}
//			System.err.println(first + " " + last + " [" + ns[0] + " " + ns[2] + " " + ns[4] + "] -> " + maxPos);
			if (maxVal == 0) {
				throw new AssertionError();
			}
			if (resPos == 0) {
				first = maxPos;
			}
			res[resPos++] = maxPos;
			--ns[maxPos];
			while (ns[(maxPos + 3) % 6] > 0) {
				if (ns[maxPos] == 0) {
					throw new AssertionError();
				}
				res[resPos++] = (maxPos + 3) % 6;
				--ns[(maxPos + 3) % 6];
				res[resPos++] = maxPos;
				--ns[maxPos];
			}
			last = maxPos;
		}
		printCase();
		for (int i = 0; i < n; i++) {
			out.print("ROYGBV".charAt(res[i]));
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