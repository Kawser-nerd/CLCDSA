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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		final int MOD = (int) (1e9 + 7);

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			long A = in.nextLong();
			long B = in.nextLong();
			long[] s = new long[n + 1];
			s[0] = -1;
			for (int i = 1; i <= n; i++) {
				s[i] = in.nextLong();
			}
			int[] lastA = calcLastFitting(s, A);
			int[] lastB = calcLastFitting(s, B);

			Tree t0 = new Tree(n + 1);
			Tree t1 = new Tree(n + 1);
			t0.add(0, 1);
			for (int i = 1; i <= n; i++) {
				int u = lastA[i];
				int v = lastB[i];
				int su = t1.sum(0, u);
				int sv = t0.sum(0, v);

				if (u != i - 1) {
					t0.clear();
				}
				if (v != i - 1) {
					t1.clear();
				}
				t0.add(i - 1, su);
				t1.add(i - 1, sv);
			}
			int ans = 0;
			ans = (ans + t0.sum(0, n - 1)) % MOD;
			ans = (ans + t1.sum(0, n - 1)) % MOD;
			out.println(ans);
		}

		private int[] calcLastFitting(long[] s, long a) {
			int[] res = new int[s.length];
			int p = 1;
			for (int i = 1; i < s.length; i++) {
				while (p < i && s[i] - s[p] >= a) {
					++p;
				}
				res[i] = p - 1;
			}
			return res;
		}

		class Tree {
			int[] a;
			int[] gen;
			int lastGen;

			Tree(int n) {
				a = new int[n];
				gen = new int[n];
				lastGen = 0;
			}

			void clear() {
				++lastGen;
			}

			void add(int pos, int val) {
				while (pos < a.length) {
					fix(pos);
					a[pos] += val;
					if (a[pos] >= MOD) {
						a[pos] -= MOD;
					}
					pos |= pos + 1;
				}
			}

			private void fix(int pos) {
				if (gen[pos] != lastGen) {
					gen[pos] = lastGen;
					a[pos] = 0;
				}
			}

			int sum(int l, int r) {
				if (l > r) {
					return 0;
				}
				int res = sum(r) - sum(l - 1);
				if (res < 0) {
					res += MOD;
				}
				return res;
			}

			int sum(int r) {
				int res = 0;
				while (r >= 0) {
					fix(r);
					res += a[r];
					if (res >= MOD) {
						res -= MOD;
					}
					r = (r & (r + 1)) - 1;
				}
				return res;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}