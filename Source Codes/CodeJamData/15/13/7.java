import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Pair {
		final int a, b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
	
	static int comparePairs(long a1, long b1, long a2, long b2) {
		return a1 != a2 ? Long.compare(a1, a2) : Long.compare(b1, b2);
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		final long x[] = new long[n];
		final long y[] = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextLong();
			y[i] = nextLong();
		}
		Pair pairs[] = new Pair[n * (n - 1) / 2];
		for (int p = 0, i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int a, b;
				if (comparePairs(x[i], y[i], x[j], y[j]) < 0) {
					a = j;
					b = i;
				} else {
					a = i;
					b = j;
				}
				pairs[p++] = new Pair(a, b);
			}
		}
		Comparator<Pair> pairCmp = new Comparator<Pair>() {
			public int compare(Pair o1, Pair o2) {
				long x1 = x[o1.b] - x[o1.a];
				long y1 = y[o1.b] - y[o1.a];
				long x2 = x[o2.b] - x[o2.a];
				long y2 = y[o2.b] - y[o2.a];
				long vmul = y1 * x2 - x1 * y2;
				if (vmul != 0) {
					return Long.signum(vmul);
				}
				long v1 = y[o1.a] * x1 - x[o1.a] * y1;
				long v2 = y[o2.a] * x1 - x[o2.a] * y1;
				return Long.compare(v1, v2);
			}
		};
		sort(pairs, pairCmp);
		Integer pointsO[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			pointsO[i] = i;
		}
		sort(pointsO, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return comparePairs(x[o1], y[o1], x[o2], y[o2]);
			}
		});
		int points[] = new int[n];
		for (int i = 0; i < n; i++) {
			points[i] = pointsO[i];
		}
		int pointsInv[] = new int[n];
		for (int i = 0; i < n; i++) {
			pointsInv[points[i]] = i;
		}
		int ans[] = new int[n];
		for (int i = 0; i < n; i++) {
			ans[points[i]] = min(i, n - i - 1);
		}
		for (int p1 = 0, p2; p1 < pairs.length; p1 = p2) {
			for (p2 = p1 + 1; p2 < pairs.length && pairCmp.compare(pairs[p1], pairs[p2]) == 0; p2++) { }
			int minPos = Integer.MAX_VALUE;
			int maxPos = Integer.MIN_VALUE;
			for (int i = p1; i < p2; i++) {
				minPos = min(minPos, pointsInv[pairs[i].a]);
				maxPos = max(maxPos, pointsInv[pairs[i].a]);
				minPos = min(minPos, pointsInv[pairs[i].b]);
				maxPos = max(maxPos, pointsInv[pairs[i].b]);
			}
			if (p2 - p1 != (maxPos - minPos) * (maxPos - minPos + 1) / 2) {
				throw new AssertionError();
			}
			for (int i = minPos; i <= maxPos; i++) {
				ans[points[i]] = min(ans[points[i]], min(minPos, n - maxPos - 1));
			}
			for (int i = minPos, j = maxPos; i < j; i++, j--) {
				int t = points[i];
				points[i] = points[j];
				points[j] = t;
				pointsInv[points[i]] = i;
				pointsInv[points[j]] = j;
			}
		}
		printlnCase();
		for (int i: ans) {
			out.println(i);
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