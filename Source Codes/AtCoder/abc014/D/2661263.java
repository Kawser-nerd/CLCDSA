import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			List<Integer>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);

			for (int i = 0; i < n-1; i++) {
				int x = in.nextInt()-1;
				int y = in.nextInt()-1;
				g[x].add(y);
				g[y].add(x);
			}

			LCA lca = new LCA(g, 0);

			int q = in.nextInt();
			for (int i = 0; i < q; i++) {
				int a = in.nextInt()-1, b = in.nextInt()-1;
				int c = lca.lca(a, b);
				out.println(lca.depth[a] + lca.depth[b] - 2*lca.depth[c] + 1);
			}

		}
	}

	private static class LCA {

		private final int logN;
		private final int n;
		private final List<Integer>[] graph;
		private final int[][] par;
		public final int[] depth;

		public LCA(List<Integer>[] g, int root) {
			this.graph = g;
			this.n = g.length;
			this.logN = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
			this.par = new int[logN][n];
			this.depth = new int[n];

			init(root);
		}

		private void init(int root) {
			bfs(root);
			for (int k = 0; k < logN - 1; k++) {
				for (int v = 0; v < n; v++) {
					if (par[k][v] < 0)
						par[k + 1][v] = -1;
					else
						par[k + 1][v] = par[k][par[k][v]];
				}
			}
		}

		private void bfs(int v) {
			Arrays.fill(depth, Integer.MAX_VALUE);
			ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
			queue.add(v);
			depth[v] = 0;
			par[0][v] = -1;
			while (!queue.isEmpty()) {
				int now = queue.poll();
				for (int p : graph[now]) {
					if (depth[p] > depth[now] + 1) {
						depth[p] = depth[now] + 1;
						queue.add(p);
						par[0][p] = now;
					}
				}
			}
		}

		public int lca(int u, int v) {
			if (depth[u] > depth[v]) {
				int tmp = u;
				u = v;
				v = tmp;
			}
			for (int k = 0; k < logN; k++) {
				if (((depth[v] - depth[u]) >> k & 1) == 1)
					v = par[k][v];
			}
			if (u == v)
				return u;

			for (int k = logN - 1; k >= 0; k--) {
				if (par[k][u] != par[k][v]) {
					u = par[k][u];
					v = par[k][v];
				}
			}
			return par[0][u];
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.