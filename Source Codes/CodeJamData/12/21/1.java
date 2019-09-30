import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ":");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
		}
		int sum = 0;
		for (int i : s) {
			sum += i;
		}
		double[] x = new double[n];
		for (int i = 0; i < n; i++) {
			x[i] = (double) s[i] / sum;
		}

		for (int i = 0; i < n; i++) {
			double left = 0, right = 1;

			while (true) {
				double mid = (left + right) * 0.5;
				if (mid <= left || mid >= right) {
					break;
				}
				if (isOk(x, 1 - mid, i, x[i] + mid)) {
					right = mid;
				} else {
					left = mid;
				}
			}
			out.print(" "+right * 100);
		}
		out.println();
	}

	static boolean isOk(double[] x, double canGive, int skip, double val) {
		double mustGive = 0;
		for (int i = 0; i < x.length; i++) {
			if (i == skip) {
				continue;
			}
			mustGive += max(0, val - x[i]);
		}
		return mustGive >= canGive;
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("a.in"));
			out = new PrintWriter("a.out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null)
				return null;
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}