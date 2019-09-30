import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
		boolean ok;

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			List<Integer>[] adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			for (int i = 0; i < n - 1; i++) {
				int u = in.nextInt() - 1;
				int v = in.nextInt() - 1;
				adj[u].add(v);
				adj[v].add(u);
			}
			if (n == 2) {
				out.println(a[0] == a[1] ? "YES" : "NO");
				return;
			}
			int root = -1;
			for (int i = 0; i < n; i++) {
				if (adj[i].size() > 1) {
					root = i;
					break;
				}
			}
			if (root < 0) {
				throw new AssertionError();
			}
			ok = true;
			// System.out.println("root = " + root);
			long excess = dfs(root, -1, adj, a);
			out.println(ok && excess == 0 ? "YES" : "NO");
		}

		private long dfs(int v, int parent, List<Integer>[] adj, int[] a) {
			List<Long> e = new ArrayList<>();
			long sum = 0;
			for (int u : adj[v]) {
				if (u == parent) {
					continue;
				}
				long cur = dfs(u, v, adj, a);
				e.add(cur);
				sum += cur;
			}
			if (e.size() == 0) {
				return a[v];
			}
			long p = sum - a[v]; // pairs
			long s = a[v] - p; // singles
			if (p < 0 || s < 0) {
				ok = false;
				return 0;
			}
			if (p > maxPairs(e)) {
				ok = false;
				return 0;
			}
			return s;
		}

		private long maxPairs(List<Long> a) {
			long free = 0;
			long pairs = 0;
			for (long x : a) {
				long s = Math.min(x, free);
				x -= s;
				free -= s;
				if (x % 2 != 0) {
					++free;
					--x;
				}
				long d = Math.min(x, 2 * pairs);
				x -= d;

				pairs += s;
				pairs += d / 2;
				free += x;
			}
			return pairs;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.