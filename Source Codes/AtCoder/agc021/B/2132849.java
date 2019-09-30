import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] x = new int[n];
			int[] y = new int[n];
			for (int i = 0; i < n; i++) {
				x[i] = in.nextInt();
				y[i] = in.nextInt();
			}

			for (int i = 0; i < n; i++) {
				double[] a = new double[n];
				int p = 0;
				for (int j = 0; j < n; j++) {
					if (j != i) {
						a[p++] = Math.atan2(y[j] - y[i], x[j] - x[i]);
					}
				}
				Arrays.sort(a, 0, p);
				a[p++] = a[0] + 2 * Math.PI;
				double max = 0;
				for (int j = 0; j + 1 < a.length; j++) {
					max = Math.max(max, a[j + 1] - a[j]);
				}
				max = Math.max(max - Math.PI, 0.0);
				out.printf("%.15f\n", max / (2 * Math.PI));
			}
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}