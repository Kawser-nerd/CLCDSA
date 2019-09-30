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
		C_LexicographicConstraints solver = new C_LexicographicConstraints();
		solver.solve(1, in, out);
		out.close();
	}

	static class C_LexicographicConstraints {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}

			int[] incs = new int[n];
			int numIncs = 0;
			for (int i = 0; i + 1 < n; i++) {
				if (a[i] >= a[i + 1]) {
					incs[numIncs++] = a[i + 1];
				}
			}
			incs[numIncs++] = 0;
			incs = Arrays.copyOf(incs, numIncs);

			int l = 0;
			int r = n;
			int[] stack = new int[n];
			int[] carry = new int[n];
			int p;
			while (r - l > 1) {
				int m = (l + r) / 2;
				p = 0;
				for (int x : incs) {
					if (p == 0 || stack[p - 1] <= x) {
						carry[p] = 1;
						stack[p++] = x;
						continue;
					}
					int c = carry[p - 1];
					while (p >= 2 && stack[p - 2] > x) {
						int between = stack[p - 1] - stack[p - 2];
						while (between > 0 && c > 0 && m > 1) {
							c /= m;
							--between;
						}
						c += carry[p - 2];
						carry[p - 1] = 0;
						--p;
					}

					int between = stack[p - 1] - x;
					while (between > 0 && c > 0 && m > 1) {
						c /= m;
						--between;
					}
					c += 1;
					carry[p - 1] = 0;
					--p;

					carry[p] = c;
					stack[p++] = x;
				}
				if (carry[0] == 1) {
					r = m;
				} else {
					l = m;
				}
			}
			out.println(r);
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