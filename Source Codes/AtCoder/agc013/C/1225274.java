import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			long L = in.nextInt();
			long t = in.nextInt();
			t *= 2;
			L *= 2;
			List<Long> aa = new ArrayList<>();
			List<Long> bb = new ArrayList<>();
			int firstA = -1;
			for (int i = 0; i < n; i++) {
				long x = in.nextInt();
				int w = in.nextInt();
				x *= 2;
				if (w == 1) {
					aa.add(x);
					if (firstA < 0) {
						firstA = i;
					}
				} else {
					bb.add(x);
				}
			}
			long[] a = toArray(aa);
			long[] b = toArray(bb);

			long[] ans = new long[n];
			int p = 0;
			for (long x : a) {
				ans[p++] = (x + t) % L;
			}
			for (long x : b) {
				ans[p++] = ((x - t) % L + L) % L;
			}

			if (a.length > 0 && b.length > 0) {
				int s = firstA;
				for (long x : b) {
					long d = ((x - a[0]) % L + L) % L;
					long numCollisions = 0;
					if (t - 1 < d / 2) {
						continue;
					}
					++numCollisions;
					numCollisions += (t - 1 - d / 2) / (L / 2);

					s = (int) ((s + numCollisions) % n);
				}

				// The point at a[0] had the number firstA.
				// It moved to (a[0] + t) mod L and changed its number to s.
				Arrays.sort(ans);
				int j = -1;
				for (int i = 0; i < ans.length; i++) {
					if (ans[i] == (a[0] + t) % L) {
						j = i;
						break;
					}
				}
				long[] nans = new long[n];
				for (int i = 0; i < n; i++) {
					nans[(s + i) % n] = ans[(j + i) % n];
				}
				ans = nans;
			}

			for (long x : ans) {
				out.println(x / 2);
			}
		}

		private long[] toArray(List<Long> lst) {
			long[] a = new long[lst.size()];
			for (int i = 0; i < a.length; i++) {
				a[i] = lst.get(i);
			}
			return a;
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