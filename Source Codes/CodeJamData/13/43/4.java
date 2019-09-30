import java.io.*;
import java.util.*;

public class C {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static void solveOneTest() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}

		int[] indexForA = new int[n + 1];
		int[] indexForB = new int[n + 1];
		int maxA = 0;

		BitSet[] g = new BitSet[n];
		for (int i = 0; i < n; i++) {
			g[i] = new BitSet(n);
		}

		for (int i = 0; i < n; i++) {
			if (a[i] > maxA) {
				maxA = a[i];
			} else {
				g[indexForA[a[i]]].set(i);
			}

			indexForA[a[i]] = i;

			if (a[i] > 1) {
				g[i].set(indexForA[a[i] - 1]);
			}

		}

		int maxB = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (b[i] > maxB) {
				maxB = b[i];
			} else {
				g[indexForB[b[i]]].set(i);
			}
			indexForB[b[i]] = i;

			if (b[i] > 1) {
				g[i].set(indexForB[b[i] - 1]);
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (!g[i].get(k)) {
					continue;
				}
				g[i].or(g[k]);
			}
		}

		int[] value = new int[n];
		boolean[] used = new boolean[n];

		for (int i = 0; i < n; i++) {
			int sizeLess = g[i].cardinality();
			int val = 0;
			while (sizeLess >= 0) {
				if (!used[val++]) {
					--sizeLess;
				}
			}
			--val;
			value[i] = val;
			used[val] = true;
			for (int j = i + 1; j < n; j++) {
				g[j].set(i, false);
			}
		}

		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(value[i]+1);
		}
		out.println();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("c.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
