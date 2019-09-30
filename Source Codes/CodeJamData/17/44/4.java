import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 0;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	void solve() throws IOException {
		int c = nextInt();
		int r = nextInt();
		int can = nextInt();
		char[][] f = new char[r][];
		for (int i = 0; i < r; i++) {
			f[i] = nextToken().toCharArray();
		}

		int[][] soldId = new int[r][c];
		int[][] turrId = new int[r][c];

		int[] soldX = new int[r * c];
		int[] soldY = new int[r * c];
		
		int[] turrX = new int[r * c];
		int[] turrY = new int[r * c];

		int solds = 0;
		int turrs = 0;

		for (int i = 0; i < r; i++) {
			Arrays.fill(soldId[i], -1);
			Arrays.fill(turrId[i], -1);
			for (int j = 0; j < c; j++) {
				if (f[i][j] == 'S') {
					soldX[solds] = i;
					soldY[solds] = j;
					soldId[i][j] = solds++;
					f[i][j] = '.';
				} else if (f[i][j] == 'T') {
					turrX[turrs] = i;
					turrY[turrs] = j;
					turrId[i][j] = turrs++;
					f[i][j] = '.';
				}
			}
		}

		int[][] matr = new int[solds][turrs];
		for (int i = 0; i < turrs; i++) {
			int[][] d = new int[r][c];
			for (int j = 0; j < r; j++) {
				Arrays.fill(d[j], INF);
			}

			int x0 = turrX[i];
			int y0 = turrY[i];

			for (int dir = 0; dir < 4; dir++) {
				int x = x0;
				int y = y0;
				while (x >= 0 && x < r && y >= 0 && y < c && f[x][y] == '.') {
					d[x][y] = 0;
					x += DX[dir];
					y += DY[dir];
				}
			}

			doBfs(r, c, f, d);

			for (int x = 0; x < r; x++) {
				for (int y = 0; y < c; y++) {
					if (soldId[x][y] != -1) {
						matr[soldId[x][y]][i] = d[x][y];
					}
				}
			}
			
		}
		
		MinCostFlowGraph g = new MinCostFlowGraph(solds + turrs + 2, solds + turrs, solds + turrs + 1);
		for (int i = 0; i < solds; i++) {
			g.addEdge(g.S, i, 1, 0);
		}
		for (int i = 0; i < turrs; i++) {
			g.addEdge(i + solds, g.T, 1, 0);
		}
		for (int i = 0; i < solds; i++) {
			for (int j = 0; j < turrs; j++) {
				if (matr[i][j] <= can) {
//					System.err.println(i + " " + j);
					g.addEdge(i, j + solds, 1, matr[i][j]);
				}
			}
		}
		
		int[] flow = g.maxFlowMinCost();
		out.println(flow[0]);
		
		int[] shoot = new int[solds];
		Arrays.fill(shoot, -1);
		
		for (int i = 0; i < solds; i++) {
			for (MinCostFlowEdge e : g.g[i]) {
				if (e.flow == 1) {
					shoot[i] = e.to - solds;
				}
			}
		}

		outer: for (int iter = 0; iter < flow[0]; iter++) {
			
			HashSet<Integer>[][] block = new HashSet[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					block[i][j] = new HashSet<>();
				}
			}
			
			for (int i = 0; i < solds; i++) {
				if (shoot[i] != -1) {
					
					int turrNow = shoot[i];
					
					int x0 = turrX[turrNow];
					int y0 = turrY[turrNow];

					for (int dir = 0; dir < 4; dir++) {
						int x = x0;
						int y = y0;
						while (x >= 0 && x < r && y >= 0 && y < c && f[x][y] == '.') {
							block[x][y].add(turrNow);
							x += DX[dir];
							y += DY[dir];
						}
					}
					
					
				}
			}
			
			for (int i = 0; i < solds; i++) {
				if (shoot[i] != -1) {
					int[][] dist = getDists(soldX[i], soldY[i], block, f);
						
					for (int x = 0; x < r; x++) {
						for (int y = 0; y < c; y++) {
							if (dist[x][y] <= can && block[x][y].contains(shoot[i])) {
								out.println((i + 1) + " " + (shoot[i] + 1));
								shoot[i] = -1;
								continue outer;
							}
						}
					}
				}
			}
			
			throw new AssertionError();
			
		}
		
	}
	
	int[][] getDists(int x0, int y0, HashSet<Integer>[][] block, char[][] f) {
		int r = f.length;
		int c = f[0].length;
		
		int[] que = new int[2 * r * c];
		int qh = 0, qt = 0;
		que[qt++] = x0;
		que[qt++] = y0;
		int[][] d = new int[r][c];
		for (int i = 0; i < r; i++) {
			Arrays.fill(d[i], INF);
		}
		
		d[x0][y0] = 0;

		while (qh < qt) {
			int x = que[qh++];
			int y = que[qh++];
			
			if (!block[x][y].isEmpty()) {
				continue;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + DX[dir];
				int ny = y + DY[dir];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c && f[nx][ny] == '.') {
					if (d[nx][ny] > d[x][y] + 1) {
						d[nx][ny] = d[x][y] + 1;
						que[qt++] = nx;
						que[qt++] = ny;
					}
				}
			}
		}
		
		return d;
		
	}

	static class MinCostFlowGraph {
		int N, S, T;
		static final int INF = Integer.MAX_VALUE / 3;

		List<MinCostFlowEdge>[] g;
		private int[] phi;
		final private int[] d;
		private boolean[] vis;
		private MinCostFlowEdge[] from;

		public MinCostFlowGraph(int n, int s, int t) {
			N = n;
			S = s;
			T = t;
			g = new List[N];
			for (int i = 0; i < N; i++) {
				g[i] = new ArrayList<>();
			}
			phi = new int[N];
			vis = new boolean[N];
			d = new int[N];
			from = new MinCostFlowEdge[N];

			cache = new Integer[N];
			for (int i = 0; i < N; i++) {
				cache[i] = i;
			}
		}

		void addEdge(int v1, int v2, int cap, int cost) {
			MinCostFlowEdge e1 = new MinCostFlowEdge(v2, cap, cost);
			MinCostFlowEdge e2 = new MinCostFlowEdge(v1, 0, -cost);
			e1.rev = e2;
			e2.rev = e1;
			g[v1].add(e1);
			g[v2].add(e2);
		}

		int curFlow = 0;
		int curCost = 0;

		Integer[] cache;
		TreeSet<Integer> set = new TreeSet<>();

		Comparator<Integer> byDist = new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(d[o1], d[o2]);
			}
		};

		void findPathELogV() {
			set.clear();
			set.add(cache[S]);
			Arrays.fill(d, INF);
			Arrays.fill(vis, false);
			d[S] = 0;
			while (!set.isEmpty()) {
				int v = set.pollFirst();
				vis[v] = true;
				if (v == T)
					break;
				List<MinCostFlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					MinCostFlowEdge e = adj.get(i);
					if (e.flow == e.cap)
						continue;
					if (d[e.to] > d[v] + e.cost + phi[v] - phi[e.to]) {
						set.remove(cache[e.to]);
						d[e.to] = d[v] + e.cost + phi[v] - phi[e.to];
						set.add(cache[e.to]);
						from[e.to] = e;
					}
				}
			}
		}

		void findPathV2() {
			Arrays.fill(d, INF);
			Arrays.fill(vis, false);
			d[S] = 0;
			while (true) {
				int v = -1;
				for (int i = 0; i < N; i++) {
					if (!vis[i] && (v == -1 || d[i] < d[v])) {
						v = i;
					}
				}
				vis[v] = true;
				if (v == T)
					break;
				List<MinCostFlowEdge> adj = g[v];
				for (int i = 0; i < adj.size(); i++) {
					MinCostFlowEdge e = adj.get(i);
					if (e.flow == e.cap)
						continue;
					if (d[e.to] > d[v] + e.cost + phi[v] - phi[e.to]) {
						d[e.to] = d[v] + e.cost + phi[v] - phi[e.to];
						from[e.to] = e;
					}
				}
			}
		}

		int[] augmentFlow(int flowLeft) {
			// returns null if it can't be augmented
			 findPathELogV();
			 if (d[T] == INF) {
				 return null;
			 }
//			 findPathV2();
			for (int i = 0; i < N; i++) {
				if (vis[i]) {
					phi[i] += d[i] - d[T];
				}
			}

			int addFlow = flowLeft;
			int costPerFlowUnit = 0;

			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				addFlow = Math.min(addFlow, e.cap - e.flow);
				costPerFlowUnit += e.cost;
			}
			
			for (int v = T; v != S; v = from[v].rev.to) {
				MinCostFlowEdge e = from[v];
				e.flow += addFlow;
				e.rev.flow -= addFlow;
			}

			return new int[] { addFlow, costPerFlowUnit };
		}

		int[] maxFlowMinCost() {
			int[] ret = new int[2];
			while (true) {
				int[] delta = augmentFlow(INF);
				if (delta == null || delta[0] == 0)
					break;
				ret[0] += delta[0];
				ret[1] += delta[0] * delta[1];
			}
			return ret;
		}
	}

	static class MinCostFlowEdge {
		int to;
		int flow, cap;

		int cost;

		MinCostFlowEdge rev;

		public MinCostFlowEdge(int to, int cap, int cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
	}


	void doBfs(int r, int c, char[][] f, int[][] d) {
		int[] que = new int[2 * r * c];
		int qh = 0, qt = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (d[i][j] == 0) {
					que[qt++] = i;
					que[qt++] = j;
				}
			}
		}

		while (qh < qt) {
			int x = que[qh++];
			int y = que[qh++];

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + DX[dir];
				int ny = y + DY[dir];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c && f[nx][ny] == '.') {
					if (d[nx][ny] > d[x][y] + 1) {
						d[nx][ny] = d[x][y] + 1;
						que[qt++] = nx;
						que[qt++] = ny;
					}
				}
			}
		}

	}

	static final int INF = Integer.MAX_VALUE / 5;

	D() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("D-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("D-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("D-large.in"));
			out = new PrintWriter("D-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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
}