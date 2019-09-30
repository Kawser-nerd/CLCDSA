import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		final int s[] = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (s[i] = nextInt());
		}
		// s[j] + sum * y[j] >= s[i] + sum * y[i]
		Integer idx[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return s[o1] - s[o2];
			}
		});
		int sums[] = new int[n];
		for (int i = 0; i < n; i++) {
			sums[i] = s[idx[i]];
			if (i > 0) {
				sums[i] += sums[i - 1];
			}
		}
		double ans[] = new double[n];
		for (int i = 0; i < n; i++) {
			double nval = (double) (sums[i] + sum) / (i + 1);
			if (i == n - 1 || nval < s[idx[i + 1]]) {
				for (int j = 0; j < n; j++) {
					ans[idx[j]] = j <= i ? (double) (nval - s[idx[j]]) / sum : 0;
				}
				break;
			}
		}
		printCase();
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i] * 100);
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