import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g1, g2;
	int n;

	static final int INF = 1_000_000_000;

	int[][] bfs(List<Integer>[] g, int root) {
		int[] dist = new int[n];
		Arrays.fill(dist, INF);
		int[] par = new int[n];
		par[root] = root;
		int[] q = new int[n];
		int head = 0, tail = 0;
		q[tail++] = root;
		dist[root] = 0;

		while (head < tail) {
			int v = q[head++];
			for (int u : g[v]) {
				if (dist[u] > dist[v] + 1) {
					dist[u] = dist[v] + 1;
					par[u] = v;
					q[tail++] = u;
				}
			}
		}

		return new int[][] { dist, par };
	}

	boolean badEdge(int v, int u, int[] par) {
		return (par[v] == u || par[u] == v) || // distance 1
				(par[par[v]] == u || par[par[u]] == v || par[v] == par[u]); // distance
																			// 2
	}

	void solve() throws IOException {
		n = nextInt();
		int x = nextInt() - 1;
		int y = nextInt() - 1;

		g1 = new List[n];
		for (int i = 0; i < n; i++) {
			g1[i] = new ArrayList<>();
		}

		g2 = new List[n];
		for (int i = 0; i < n; i++) {
			g2[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g1[v].add(u);
			g1[u].add(v);
		}

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g2[v].add(u);
			g2[u].add(v);
		}

		int[][] info1 = bfs(g1, x);
		int[][] info2 = bfs(g2, y);
		
//		System.err.println(Arrays.toString(info2[1]));

		boolean[] safeNodes = new boolean[n];
		for (int v = 0; v < n; v++) {
			for (int u : g1[v]) {
				if (u < v) {
					continue;
				}
				
//				System.err.println(v + " " + u + " " + badEdge(v, u, info2[1]));
				
				if (!badEdge(v, u, info2[1])) {
					safeNodes[v] = safeNodes[u] = true;
				}
			}
		}

		int[] dist = new int[n];
		Arrays.fill(dist, INF);
		int[] q = new int[n];
		int head = 0, tail = 0;
		q[tail++] = x;
		dist[x] = 0;

		int ans = 0;

		while (head < tail) {
			int v = q[head++];
			if (safeNodes[v]) {
				out.println(-1);
				return;
			}
			ans = Math.max(ans, info2[0][v]);
			for (int u : g1[v]) {
				if (info1[0][u] >= info2[0][u]) {
					continue;
				}
				if (dist[u] > dist[v] + 1) {
					dist[u] = dist[v] + 1;
					q[tail++] = u;
				}
			}
		}
		
		out.println(ans * 2);

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
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
		} catch (IOException e) {
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.