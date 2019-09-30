import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ": ");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		int[] d = new int[n];
		int[] l = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = nextInt();
			l[i] = nextInt();
		}
		int D = nextInt();
		int[] max = new int[n];
		fill(max, -1);
		max[0] = d[0];
		boolean yes = false;
		for (int i = 0; i < n; i++) {
			if (max[i] < 0) {
				continue;
			}
			int to = max[i] + d[i];
			if (to >= D) {
				yes = true;
			}
			for (int j = i + 1; j < n && d[j] <= to; j++) {
				int ok = min(l[j], d[j] - d[i]);
				max[j] = max(max[j], ok);
			}
		}
		out.println(yes?"YES":"NO");
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("A.in"));
			out = new PrintWriter("A.out");
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