import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"C-small.in")));
		writer = new PrintWriter("C-small.out");
		banana();
		reader.close();
		writer.close();
	}

	static void good(int[] a) {
		int n = a.length;
		for (int i = 0; i < a.length; i++) {
			a[i] = i;
		}
		for (int k = 0; k < n; k++) {
			int p = (int) (Math.random() * (n - k)) + k;
			int t = a[k];
			a[k] = a[p];
			a[p] = t;
		}
	}

	static void bad(int[] a) {
		int n = a.length;
		for (int i = 0; i < a.length; i++) {
			a[i] = i;
		}
		for (int k = 0; k < n; k++) {
			int p = (int) (Math.random() * n);
			int t = a[k];
			a[k] = a[p];
			a[p] = t;
		}
	}

	static void banana() throws IOException {
		// int[] a = new int[1000];
		// int n = 1000;
		//
		// int tstGB = 0;
		// int tstBG = 0;
		//
		// double aveG = 0;
		// for (int i = 0; i < n; i++) {
		// good(a);
		// int res = test(a);
		// if (res <= 485)
		// tstGB++;
		// aveG += 1.0 * res / n;
		// }
		//
		// double aveB = 0;
		// for (int i = 0; i < n; i++) {
		// bad(a);
		// int res = test(a);
		// if (res > 485)
		// tstBG++;
		// aveB += 1.0 * res / n;
		// }
		//
		// System.out.println("aveG " + aveG);
		// System.out.println("aveB " + aveB);
		// System.out.println("tstGB " + tstGB + " of " + n);
		// System.out.println("tstBG " + tstBG + " of " + n);

		int T = nextInt();
		for (int t = 0; t < T; t++) {
			writer.print("Case #" + (t + 1) + ": ");
			solve();
		}
	}

	static int test(int[] a) {
		int ret = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] < i)
				ret++;
		}
		return ret;
	}

	static void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int res = test(a);
		if (res > 485) {
			writer.println("GOOD");
		} else {
			writer.println("BAD");
		}
	}
}