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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		final int MOD = (int) (1e9 + 7);

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			long[] d = new long[n];
			long[] s = new long[n];
			d[0] = n % MOD;
			s[0] = d[0];
			for (int i = 1; i < n; i++) {
				// Place a "1".
				d[i] = d[i - 1];
				// Place x,y > 1.
				d[i] = (d[i] + (long) (n - 1) * (n - 1) % MOD) % MOD;
				// Place x>1, followed by x ones.
				d[i] = (d[i] + sum(s, i - n - 1, i - 2 - 1)) % MOD;
				s[i] = (s[i - 1] + d[i]) % MOD;
			}
			out.println(d[n - 1]);
		}

		private long sum(long[] s, int l, int r) {
			if (l > r) {
				return 0;
			}
			if (r < 0) {
				return (r - l + 1) % MOD;
			}
			long res;
			if (l < 0) {
				res = sum(s, 0, r) - l;
			} else {
				res = s[r] - (l == 0 ? 0 : s[l - 1]);
			}
			res %= MOD;
			if (res < 0) {
				res += MOD;
			}
			return res;
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