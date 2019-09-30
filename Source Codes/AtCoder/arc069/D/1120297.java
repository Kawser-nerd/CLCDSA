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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		int n;
		Point[] ps;
		SAT2Solver solver;
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
				solver = new SAT2Solver(n + (maxNodeId + 1));
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
			solver.clear();
			initTree(0, 0, ps.length - 1, false);
			int j = 0;
			for (int i = 0; i < ps.length; i++) {
				while (j < ps.length && ps[j].x - ps[i].x < d) {
					++j;
				}
				block(0, 0, ps.length - 1, i + 1, j - 1, i);
			}
			return solver.solve();
		}

		private void block(int root, int l, int r, int L, int R, int condition) {
			if (l > r || l > R || L > r || L > R) {
				return;
			}
			if (l == L && r == R) {
				// If the conditioned point takes on its .f value, the root is blocked.
				solver.addClause(ps[condition].id, n + root, ps[condition].f, true);
				solver.addClause(n + root, ps[condition].id, false, !ps[condition].f);
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
				solver.addClause(n + root, ps[l].id, true, !ps[l].f);
				solver.addClause(ps[l].id, n + root, ps[l].f, false);
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
				solver.addClause(n + root, n + child, true, true);
				solver.addClause(n + child, n + root, false, false);
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
			}

			public void clear() {
				Arrays.fill(firstEdge, -1);
				numEdges = 0;
			}

			public void addClause(int v1, int v2, boolean neg1, boolean neg2) {
				if (neg1) {
					v1 = negate(v1);
				}
				if (neg2) {
					v2 = negate(v2);
				}
				addEdge(v1, v2);
			}

			private void addEdge(int a, int b) {
				int e = numEdges++;
				if (e >= edgeDst.length) {
					int k = edgeDst.length;
					int[] dst = new int[3 * k / 2 + 1];
					System.arraycopy(edgeDst, 0, dst, 0, k);
					edgeDst = dst;
					int[] nxt = new int[3 * k / 2 + 1];
					System.arraycopy(edgeNxt, 0, nxt, 0, k);
					edgeNxt = nxt;
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
				List<Integer>[] invertedCompEdges = new List[numComps];
				for (int i = 0; i < numComps; i++) {
					invertedCompEdges[i] = new ArrayList<>();
				}
				for (int i = 0; i < 2 * n; i++) {
					for (int e = firstEdge[i]; e >= 0; e = edgeNxt[e]) {
						int j = edgeDst[e];
						invertedCompEdges[comp[j]].add(comp[i]);
					}
				}
				boolean[] compIsTrue = new boolean[numComps];
				Arrays.fill(compIsTrue, true);
				for (int c = 0; c < numComps; c++) {
					if (!compIsTrue[c]) {
						continue;
					}
					for (int i = firstInComp[c]; i >= 0; i = nextSameComp[i]) {
						int nc = comp[negate(i)];
						if (c == nc) {
							return false;
						}
					}
					for (int i = firstInComp[c]; i >= 0; i = nextSameComp[i]) {
						int nc = comp[negate(i)];
						dfsReject(nc, invertedCompEdges, compIsTrue);
					}
				}
				for (int i = 0; i < 2 * n; i++) {
					isTrue[i] = compIsTrue[comp[i]];
				}
				for (int i = 0; i < n; i++) {
					if (isTrue[i] && isTrue[negate(i)]) {
						throw new AssertionError();
					}
					if (!isTrue[i] && !isTrue[negate(i)]) {
						return false;
					}
				}
				return true;
			}

			private int negate(int i) {
				return i + (i < n ? n : -n);
			}

			private void dfsReject(int c, List<Integer>[] invertedCompEdges, boolean[] compIsTrue) {
				if (!compIsTrue[c]) {
					return;
				}
				compIsTrue[c] = false;
				for (int p : invertedCompEdges[c]) {
					dfsReject(p, invertedCompEdges, compIsTrue);
				}
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.