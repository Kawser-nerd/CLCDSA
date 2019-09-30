import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int fr, to;
		long flow, cap;
		Edge rev;

		Edge(int fr, int to, long cap) {
			this.fr = fr;
			this.to = to;
			this.cap = cap;
		}
	}

	class Flow {
		int n;
		ArrayList<Edge>[] g;

		Flow(int n) {
			this.n = n;
			g = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<>();
			}
			q = new int[n];
			h = new int[n];
			cur = new int[n];
		}

		void addEdge(int fr, int to, long cap) {
			Edge e1 = new Edge(fr, to, cap);
			Edge e2 = new Edge(to, fr, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
		}

		int[] h;
		int[] cur;
		int[] q;

		boolean bfs() {
			int qIt = 0, qSz = 0;
			q[qSz++] = 0;
			Arrays.fill(h, -1);
			h[0] = 0;
			while (qIt < qSz) {
				int v = q[qIt++];
				for (Edge e : g[v]) {
					if (e.flow == e.cap)
						continue;
					if (h[e.to] == -1) {
						h[e.to] = h[e.fr] + 1;
						q[qSz++] = e.to;
					}
				}
			}
			return h[n - 1] != -1;
		}

		long dfs(int v, long flow) {
			if (v == n - 1 || flow == 0)
				return flow;
			for (; cur[v] < g[v].size(); cur[v]++) {
				Edge e = g[v].get(cur[v]);
				if (h[e.to] != h[e.fr] + 1 || e.flow == e.cap)
					continue;
				long add = dfs(e.to, Math.min(flow, e.cap - e.flow));
				if (add == 0)
					continue;
				e.flow += add;
				e.rev.flow -= add;
				return add;
			}
			return 0;
		}

		long flow() {
			long res = 0;
			while (bfs()) {
				Arrays.fill(cur, 0);
				while (true) {
					long add = dfs(0, Long.MAX_VALUE);
					if (add == 0)
						break;
					res += add;
				}
			}
			return res;
		}
	}

	boolean isOk(boolean[][] g) {
		int n = g.length;
		for (int id = 0; id < n; id++) {
			boolean[] left = new boolean[n];
			boolean[] right = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (g[i][id]) {
					left[i] = true;
					for (int j = 0; j < n; j++) {
						if (j != id && g[i][j]) {
							right[j] = true;
						}
					}
				}
			}
			Flow f = new Flow(2 + n * 2);
			int cntLeft = 0;
			for (int i = 0; i < n; i++) {
				if (left[i]) {
					cntLeft++;
					f.addEdge(0, 1 + i, 1);
				}
			}
			for (int i = 0; i < n; i++) {
				if (right[i]) {
					f.addEdge(1 + n + i, f.n - 1, 1);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (g[i][j]) {
						f.addEdge(1 + i, 1 + n + j, 1);
					}
				}
			}
			if (f.flow() == cntLeft) {
				return false;
			}
		}
		return true;
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			boolean[][] graph = new boolean[n][n];
			for (int i = 0; i < n; i++) {
				String s = in.next();
				for (int j = 0; j < n; j++) {
					graph[i][j] = s.charAt(j) == '1';
				}
			}
			int res = 12345;
			int m = n * n;
			for (int mask = 0; mask < 1 << m; mask++) {
				boolean[][] g = new boolean[n][n];
				int it = 0;
				boolean fail = false;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						int ne = ((1 << it) & mask) != 0 ? 1 : 0;
						if (graph[i][j] && ne == 1) {
							fail = true;
						}
						g[i][j] = graph[i][j] || (ne == 1);
						it++;
					}
				}
				if (!fail && Integer.bitCount(mask) < res) {
					if (isOk(g)) {
						res = Integer.bitCount(mask);
					}
				}
			}
			out.println(res);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}