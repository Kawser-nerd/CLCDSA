import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		int n;
		List<Integer>[] adj;
		boolean[] used;
		int[] mex;

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			n = in.nextInt();

			adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			for (int i = 0; i < n; i++) {
				int a = in.nextInt() - 1;
				int b = i;
				adj[a].add(b);
			}

			int[] cycle = new SingleCycleFinder().findCycle(adj);
			if (cycle == null) {
				out.println("POSSIBLE");
				return;
			}

			boolean[] onCycle = new boolean[n];
			for (int v : cycle) {
				onCycle[v] = true;
			}

			used = new boolean[n];
			mex = new int[n];
			for (int v : cycle) {
				for (int u : adj[v]) {
					if (!onCycle[u]) {
						findMex(u);
					}
				}
			}

			int[] candCol = new int[2];
			Arrays.fill(candCol, -1);
			int s = cycle[0];
			{
				for (int u : adj[s]) {
					if (!onCycle[u]) {
						used[mex[u]] = true;
					}
				}
				for (int i = 0; i < n; i++) {
					if (used[i]) {
						continue;
					}
					if (candCol[0] < 0) {
						candCol[0] = i;
					} else if (candCol[1] < 0) {
						candCol[1] = i;
					} else {
						break;
					}
				}
				for (int u : adj[s]) {
					if (!onCycle[u]) {
						used[mex[u]] = false;
					}
				}
			}

			for (int step = 0; step < 2; step++) {
				mex[s] = candCol[step];
				if (mex[s] < 0) {
					continue;
				}
				for (int i = cycle.length - 1; i > 0; i--) {
					calcMex(cycle[i]);
				}
				if (check()) {
					out.println("POSSIBLE");
					return;
				}
			}

			out.println("IMPOSSIBLE");
		}

		private void findMex(int v) {
			for (int u : adj[v]) {
				findMex(u);
			}
			calcMex(v);
		}

		private void calcMex(int v) {
			for (int u : adj[v]) {
				used[mex[u]] = true;
			}
			mex[v] = 0;
			while (used[mex[v]]) {
				++mex[v];
			}
			for (int u : adj[v]) {
				used[mex[u]] = false;
			}
		}

		private boolean check() {
			boolean res = true;
			for (int i = 0; i < n; i++) {
				for (int j : adj[i]) {
					used[mex[j]] = true;
				}
				for (int c = 0; c < mex[i]; c++) {
					if (!used[c]) {
						res = false;
					}
				}
				if (used[mex[i]]) {
					res = false;
				}
				for (int j : adj[i]) {
					used[mex[j]] = false;
				}
			}
			return res;
		}

		class SingleCycleFinder {
			int n;
			List<Integer>[] adj;
			int[] col;
			int[] parent;
			int c1;
			int c2;

			int[] findCycle(List<Integer>[] adj) {
				this.n = adj.length;
				this.adj = adj;

				col = new int[n];
				parent = new int[n];
				Arrays.fill(parent, -1);
				c1 = -1;
				c2 = -1;

				for (int i = 0; i < n; i++) {
					if (col[i] == 0) {
						dfs(i);
					}
				}

				if (c1 < 0) {
					return null;
				}

				int cycleSize = 0;
				for (int v = c1; ; v = parent[v]) {
					cycleSize++;
					if (v == c2) {
						break;
					}
				}
				int[] res = new int[cycleSize];
				for (int v = c1; ; v = parent[v]) {
					--cycleSize;
					res[cycleSize] = v;
					if (v == c2) {
						break;
					}
				}
				return res;
			}

			private void dfs(int v) {
				col[v] = 1;
				for (int u : adj[v]) {
					if (col[u] == 0) {
						parent[u] = v;
						dfs(u);
					} else if (col[u] == 1) {
						c1 = v;
						c2 = u;
					}
				}
				col[v] = 2;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.