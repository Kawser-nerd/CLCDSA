import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
		ProblemB solver = new ProblemB();
		solver.solve(1, in, out);
		out.close();
	}

	static class ProblemB {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			long X = in.nextInt();
			long[] x = new long[n];
			for (int i = 0; i < n; i++) {
				x[i] = in.nextInt();
			}

			long big = 1;
			for (int i = 0; i < n; i++) {
				big += x[i] + X + 4 * x[i] + X;
			}

			long[] s = new long[n + 1];
			for (int i = 0; i < n; i++) {
				s[i + 1] = s[i] + x[i];
			}

			long ans = big;
			for (int k = 1; k <= n; k++) {
				int groupId = 0;
				long cur = k * X;
				for (int i = n - 1; i >= 0; i -= k) {
					long cost = 5 + 2 * Math.max(0, groupId - 1);
					++groupId;

					int r = i;
					int l = Math.max(0, i - k + 1);
					cur = Math.min(big, cur + cost * (s[r + 1] - s[l]));
				}
				ans = Math.min(ans, cur);
			}

			out.println(ans + (long) n * X);
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