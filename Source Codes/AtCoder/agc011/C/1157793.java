import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		boolean twoCol;
		int size;

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			List<Integer>[] adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList();
			}
			for (int i = 0; i < m; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			int[] col = new int[n];
			long numNonTwoCol = 0;
			long numTwoCol = 0;
			long numSizeOne = 0;
			List<Integer> sizes = new ArrayList<>();
			List<Boolean> twoC = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (col[i] == 0) {
					twoCol = true;
					size = 0;
					dfs(i, 1, col, adj);
					sizes.add(size);
					twoC.add(twoCol);
					if (size == 1) {
						++numSizeOne;
					} else if (twoCol) {
						++numTwoCol;
					} else {
						++numNonTwoCol;
					}
				}
			}
			long ans = 0;
			for (int i = 0; i < sizes.size(); i++) {
				int size = sizes.get(i);
				boolean tc = twoC.get(i);
				if (size == 1) {
					ans += n;
					continue;
				}
				if (tc) {
					ans += numNonTwoCol + numSizeOne * size + 2 * numTwoCol;
				} else {
					ans += numNonTwoCol + numSizeOne * size + numTwoCol;
				}
			}
			out.println(ans);
		}

		private void dfs(int v, int c, int[] col, List<Integer>[] adj) {
			col[v] = c;
			++size;
			for (int u : adj[v]) {
				if (col[u] == 0) {
					dfs(u, 3 - c, col, adj);
				} else if (col[u] != 3 - c) {
					twoCol = false;
				}
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