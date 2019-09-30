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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		int n;
		Point[] ps;
		SAT2Solver sat2;
		int maxNodeId;

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			// n <= 10^4, TL 5 sec.
			n = in.nextInt();
			int min = Integer.MAX_VALUE;
			int max = Integer.MIN_VALUE;
			ps = new Point[2 * n];
			for (int i = 0; i < n; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				min = Math.min(min, x);
				min = Math.min(min, y);
				max = Math.max(max, x);
				max = Math.max(max, y);
				ps[2 * i] = new Point(x, i, true);
				ps[2 * i + 1] = new Point(y, i, false);
			}
			Arrays.sort(ps);
			{
				maxNodeId = 0;
				initTree(0, 0, ps.length - 1, true);
				sat2 = new SAT2Solver(n + (maxNodeId + 1));
			}
			int l = 0;
			int r = max - min + 1;
			while (r - l > 1) {
				int m = l + (r - l) / 2;
				if (can(m)) {
					l = m;
				} else {
					r = m;
				}
			}
			out.println(l);
		}

		private boolean can(int d) {
			sat2.clear();
			initTree(0, 0, ps.length - 1, false);
			int j = 0;
			for (int i = 0; i < ps.length; i++) {
				while (j < ps.length && ps[j].x - ps[i].x < d) {
					++j;
				}
				block(0, 0, ps.length - 1, i + 1, j - 1, i);
			}
			return sat2.solve();
		}

		private void block(int root, int l, int r, int L, int R, int condition) {
			if (l > r || l > R || L > r || L > R) {
				return;
			}
			if (l == L && r == R) {
				// If the conditioned point takes on its .f value, the root is blocked.
				int a = 2 * ps[condition].id;
				int b = 2 * (n + root) + 1;
				if (ps[condition].f) {
					a ^= 1;
				}
				sat2.addImplication(a, b);
				return;
			}
			int m = (l + r) / 2;
			block(2 * root + 1, l, m, L, Math.min(m, R), condition);
			block(2 * root + 2, m + 1, r, Math.max(m + 1, L), R, condition);
		}

		private void initTree(int root, int l, int r, boolean countOnly) {
			maxNodeId = Math.max(maxNodeId, root);
			if (l == r) {
				// If a leaf node is blocked, the corresponding point cannot take on its .f value.
				if (countOnly) {
					return;
				}
				int a = 2 * (n + root) + 1;
				int b = 2 * ps[l].id;
				if (!ps[l].f) {
					b ^= 1;
				}
				sat2.addImplication(a, b);
				return;
			}
			int m = (l + r) / 2;
			initTree(2 * root + 1, l, m, countOnly);
			initTree(2 * root + 2, m + 1, r, countOnly);
			if (countOnly) {
				return;
			}
			for (int child = 2 * root + 1; child <= 2 * root + 2; child++) {
				// If the root is blocked, so are its children.
				sat2.addImplication(2 * (n + root) + 1, 2 * (n + child) + 1);
			}
		}

		class Point implements Comparable<Point> {
			int x;
			int id;
			boolean f;

			Point(int x, int id, boolean f) {
				this.x = x;
				this.id = id;
				this.f = f;
			}

			public int compareTo(Point o) {
				return x - o.x;
			}

		}

		class SAT2Solver {
			boolean[] isTrue;
			int n;
			int numComps;
			int[] low;
			int[] vis;
			int[] comp;
			boolean[] onStack;
			int[] stack;
			int sp;
			int globalTime;
			int numEdges;
			int[] firstEdge;
			int[] edgeDst = new int[10];
			int[] edgeNxt = new int[10];

			SAT2Solver(int n) {
				this.n = n;
				isTrue = new boolean[2 * n];
				vis = new int[2 * n];
				low = new int[2 * n];
				stack = new int[2 * n];
				comp = new int[2 * n];
				onStack = new boolean[2 * n];
				firstEdge = new int[2 * n];
				clear();
			}

			public void clear() {
				Arrays.fill(firstEdge, -1);
				numEdges = 0;
			}

			public void addImplication(int a, int b) {
				addEdge(a, b);
				addEdge(b ^ 1, a ^ 1);
			}

			private void addEdge(int a, int b) {
				int e = numEdges++;
				if (e >= edgeDst.length) {
					int k = edgeDst.length;
					edgeDst = Arrays.copyOf(edgeDst, k * 3 / 2 + 1);
					edgeNxt = Arrays.copyOf(edgeNxt, k * 3 / 2 + 1);
				}
				edgeDst[e] = b;
				edgeNxt[e] = firstEdge[a];
				firstEdge[a] = e;
			}

			public boolean solve() {
				Arrays.fill(vis, -1);
				Arrays.fill(onStack, false);
				sp = 0;
				globalTime = 0;
				numComps = 0;
				for (int i = 0; i < 2 * n; i++) {
					if (vis[i] < 0) {
						dfsTarjan(i);
					}
				}
				int[] firstInComp = new int[numComps];
				Arrays.fill(firstInComp, -1);
				int[] nextSameComp = new int[2 * n];
				for (int i = 0; i < 2 * n; i++) {
					int c = comp[i];
					nextSameComp[i] = firstInComp[c];
					firstInComp[c] = i;
				}
				int[] compStatus = new int[numComps];
				final int UNKNOWN = 0;
				final int TRUE = 1;
				final int FALSE = 2;
				for (int c = 0; c < numComps; c++) {
					if (compStatus[c] != UNKNOWN) {
						continue;
					}
					for (int i = firstInComp[c]; i >= 0; i = nextSameComp[i]) {
						int nc = comp[i ^ 1];
						if (c == nc) {
							return false;
						}
					}
					compStatus[c] = TRUE;
					for (int i = firstInComp[c]; i >= 0; i = nextSameComp[i]) {
						int nc = comp[i ^ 1];
						compStatus[nc] = FALSE;
					}
				}
				for (int i = 0; i < 2 * n; i++) {
					isTrue[i] = compStatus[comp[i / 2]] == TRUE;
				}
				return true;
			}

			void dfsTarjan(int v) {
				vis[v] = globalTime;
				low[v] = globalTime;
				++globalTime;
				stack[sp++] = v;
				onStack[v] = true;
				for (int e = firstEdge[v]; e >= 0; e = edgeNxt[e]) {
					int u = edgeDst[e];
					if (vis[u] < 0) {
						dfsTarjan(u);
						if (low[v] > low[u]) {
							low[v] = low[u];
						}
					} else if (onStack[u] && low[v] > vis[u]) {
						low[v] = vis[u];
					}
				}
				if (low[v] == vis[v]) {
					while (true) {
						int u = stack[--sp];
						onStack[u] = false;
						comp[u] = numComps;
						if (u == v) {
							break;
						}
					}
					++numComps;
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
}