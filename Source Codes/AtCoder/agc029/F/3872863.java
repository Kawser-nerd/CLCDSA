import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	List<Integer>[] where;

	void submit() {
		int n = nextInt();
		int[][] a = new int[n - 1][];
		for (int i = 0; i < n - 1; i++) {
			int k = nextInt();
			a[i] = new int[k];
			for (int j = 0; j < k; j++) {
				a[i][j] = nextInt() - 1;
			}
		}

		where = new List[n];
		for (int i = 0; i < n; i++) {
			where[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			for (int v : a[i]) {
				where[v].add(i);
			}
		}

		FlowGraph g = new FlowGraph(2 * n + 1, 2 * n - 1, 2 * n);
		for (int i = 0; i < n; i++) {
			g.addDirectedEdge(g.S, i, 1);
		}
		for (int i = 0; i < n - 1; i++) {
			g.addDirectedEdge(i + n, g.T, 1);
		}

		for (int i = 0; i < n - 1; i++) {
			for (int v : a[i]) {
				g.addDirectedEdge(v, i + n, 1);
			}
		}

		if (g.maxFlow() != n - 1) {
			out.println(-1);
			return;
		}

		match = new int[n - 1];

		Arrays.fill(match, -1);
		int src = -1;
		outer: for (int i = 0; i < n; i++) {
			for (FlowEdge e : g.g[i]) {
				if (e.flow == 1) {
					match[e.to - n] = i;
					continue outer;
				}
			}
			src = i;
		}

		vis1 = new boolean[n];
		vis2 = new boolean[n];

		ans = new int[2 * n - 2];
		Arrays.fill(ans, -1);

		dfs(src);

		if (Arrays.stream(ans).anyMatch(x -> x == -1)) {
			out.println(-1);
		} else {
			for (int i = 0; i < ans.length; i += 2) {
				out.println((ans[i] + 1) + " " + (ans[i + 1] + 1));
			}
		}

	}

	boolean[] vis1, vis2;
	int[] match;

	int[] ans;

	void dfs(int v) {
		vis1[v] = true;
		for (int u : where[v]) {
			if (vis2[u]) {
				continue;
			}
			vis2[u] = true;
			if (vis1[match[u]]) {
				throw new AssertionError();
			}
			ans[2 * u] = v;
			ans[2 * u + 1] = match[u];
			dfs(match[u]);
		}
	}

	static class FlowGraph {
		int N, S, T;
		static final int INF = Integer.MAX_VALUE / 3;

		List<FlowEdge>[] g;

		private int[] dist;
		private Deque<Integer> q;
		private int[] ptr;

		public FlowGraph(int n, int s, int t) {
			N = n;
			S = s;
			T = t;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			dist = new int[N];
			q = new ArrayDeque<>();
			ptr = new int[N];
		}

		public void addDirectedEdge(int v1, int v2, int cap) {
			FlowEdge e1 = new FlowEdge(v2, cap);
			FlowEdge e2 = new FlowEdge(v1, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		public void addUndirectedEdge(int v1, int v2, int cap) {
			FlowEdge e1 = new FlowEdge(v2, cap);
			FlowEdge e2 = new FlowEdge(v1, cap);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		private boolean bfs() {
			Arrays.fill(dist, INF);
			dist[S] = 0;
			q.clear();
			q.add(S);

			while (!q.isEmpty()) {
				int v = q.poll();
				List<FlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					FlowEdge e = adj.get(i);
					if (e.flow < e.cap && dist[e.to] > dist[v] + 1) {
						dist[e.to] = dist[v] + 1;
						q.add(e.to);
					}
				}
			}
			return dist[T] != INF;
		}

		private int dfs(int v, int curFlow) {
			if (v == T)
				return curFlow;
			List<FlowEdge> adj = g[v];
			for (; ptr[v] < adj.size(); ptr[v]++) {
				FlowEdge e = adj.get(ptr[v]);
				if (dist[e.to] == dist[v] + 1 && e.flow != e.cap) {
					int go = dfs(e.to, Math.min(curFlow, e.cap - e.flow));
					if (go != 0) {
						e.flow += go;
						e.rev.flow -= go;
						return go;
					}
				}
			}
			return 0;
		}

		public int maxFlow() {
			int flow = 0;

			while (bfs()) {
				Arrays.fill(ptr, 0);
				int addFlow;
				do {
					addFlow = dfs(S, INF);
					flow += addFlow;
				} while (addFlow > 0);
			}

			return flow;
		}

	}

	static class FlowEdge {
		int to;
		int flow, cap;

		FlowEdge rev;

		public FlowEdge(int to, int cap) {
			this.to = to;
			this.cap = cap;
		}
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.