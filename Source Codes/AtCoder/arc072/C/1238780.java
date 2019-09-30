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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskE {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int D = in.nextInt();
			int[] d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = in.nextInt();
			}
			int numQueries = in.nextInt();
			Query[] queries = new Query[numQueries];
			for (int i = 0; i < numQueries; i++) {
				int q = in.nextInt() - 1;
				queries[i] = new Query();
				queries[i].id = i;
				queries[i].x = q;
			}

			// The suffix starting from i can represent any number in [1, f[i]].
			int[] f = new int[n + 1];
			f[n] = 0;
			for (int i = n - 1; i >= 0; i--) {
				int x = f[i + 1];
				f[i] = x;
				if (x + 1 > d[i] / 2) {
					f[i] = x + d[i];
				}
			}

			{
				int i = 0;
				int x = D;
				Arrays.sort(queries, (a, b) -> (a.x - b.x));
				for (Query q : queries) {
					while (i < q.x) {
						int nx = Math.abs(x - d[i]);
						x = Math.min(x, nx);
						i++;
					}
					q.ans = f[i + 1] < x;
				}
			}

			boolean[] ans = new boolean[numQueries];
			for (Query q : queries) {
				ans[q.id] = q.ans;
			}
			for (int i = 0; i < numQueries; i++) {
				out.println(ans[i] ? "YES" : "NO");
			}
		}

		class Query {
			int x;
			int id;
			boolean ans;

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