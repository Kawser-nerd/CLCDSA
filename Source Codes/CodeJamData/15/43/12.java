import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		SAMPLE, SMALL, LARGE;
	}

	static final InputType currentInputType = InputType.LARGE;
	static final int attemptNumber = 0; // for small inputs only

	void solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[n][];
		HashMap<String, Integer> easy = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String[] tmp = nextString().split(" ");
			a[i] = new int[tmp.length];
			int j = 0;
			for (String s : tmp) {
				int value;
				if (!easy.containsKey(s)) {
					value = easy.size();
					easy.put(s, value);
				} else {
					value = easy.get(s);
				}
				a[i][j++] = value;
			}
		}
		
//		System.err.println(Arrays.deepToString(a));
		
		int vs = easy.size();
		
		FlowGraph g = new FlowGraph(2 * vs + 2, 2 * vs, 2 * vs + 1);
		
		int INF = 1000000;
		
		for (int i = 0; i < vs; i++) {
			g.addDirectedEdge(i, i + vs, 1);
			g.addDirectedEdge(i + vs, i, INF);
		}
		
		for (int x : a[0]) {
			g.addDirectedEdge(x + vs, g.T, INF);
		}
		
		for (int x : a[1]) {
			g.addDirectedEdge(g.S, x, INF);
		}
		
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < a[i].length; j++)
				for (int k = j + 1; k < a[i].length; k++) {
					int v1 = a[i][j];
					int v2 = a[i][k];
					if (v1 != v2) {
						g.addDirectedEdge(v1 + vs, v2, INF);
						g.addDirectedEdge(v2 + vs, v1, INF);
					}
				}
		}
		
		out.println(g.maxFlow());
		
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

	void inp() throws IOException {
		switch (currentInputType) {
		case SAMPLE:
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		case SMALL:
			String fileName = "C-small-attempt" + attemptNumber;
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		case LARGE:
			fileName = "C-large";
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		}
		int test = nextInt();
		for (int i = 1; i <= test; i++) {
			System.err.println("Running test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (Exception e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
