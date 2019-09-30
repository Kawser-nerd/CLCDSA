import java.io.*;
import java.util.*;

public class Willow {

	FastScanner in;
	PrintWriter out;

	class Edge {
		int from, to, id;

		public Edge(int from, int to, int id) {
			super();
			this.from = from;
			this.to = to;
			this.id = id;
		}

	}

	List<Edge>[] graph;
	int[] cost;

	boolean[][][] visEdge;
	boolean[][][] visVert;
	boolean[] used;

	boolean go(int from, int p, int to, boolean[] used, boolean[] usedV) {
		if (from == to) {
			usedV[from] = true;
			return true;
		}

		for (Edge e : graph[from]) {
			if (e.to != p) {
				boolean ret = go(e.to, from, to, used, usedV);
				if (ret) {
					used[e.id] = true;
					usedV[from] = true;
					return true;
				}
			}
		}
		return false;
	}

	Integer[][][][] val;

	int getValue(int from1, int now1, int from2, int now2) {
//		System.err.println(from1 + " " + now1 + " " + from2 + " " + now2);
		if (val[from1][now1][from2][now2] != null) {
			return val[from1][now1][from2][now2];
		}

		int ret = Integer.MIN_VALUE / 2;

		boolean can1 = false, can2 = false;
		for (Edge e : graph[now1]) {
			if (!visEdge[from1][now1][e.id] && !visEdge[from2][now2][e.id]) {
				can1 = true;
			}
		}

		for (Edge e : graph[now2]) {
			if (!visEdge[from1][now1][e.id] && !visEdge[from2][now2][e.id]) {
				can2 = true;
			}
		}
		
		if (can1) {
			for (Edge e : graph[now1]) {
				if (!visEdge[from1][now1][e.id] && !visEdge[from2][now2][e.id]) {
					int add = visVert[from2][now2][e.to] ? 0 : cost[e.to];
					ret = Math.max(ret, add - getValue(from2, now2, from1, e.to));
				}
			}
		} else if (can2) {
			ret = -getValue(from2, now2, from1, now1);
		} else {
			ret = 0;
		}

		return val[from1][now1][from2][now2] = ret;
	}

	public void solve() {
		int n = in.nextInt();
		cost = new int[n];
		for (int i = 0; i < n; i++) {
			cost[i] = in.nextInt();
		}

		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 1; i < n; i++) {
			int j = in.nextInt();
			Edge st = new Edge(i - 1, j - 1, i - 1);
			Edge rev = new Edge(j - 1, i - 1, i - 1);
			graph[i - 1].add(st);
			graph[j - 1].add(rev);
		}

		visEdge = new boolean[n][n][n - 1];
		visVert = new boolean[n][n][n];
		used = new boolean[n];

		for (int from = 0; from < n; from++) {
			for (int to = 0; to < n; to++) {
				go(from, -1, to, visEdge[from][to], visVert[from][to]);
			}
		}

		val = new Integer[n][n][n][n];
		int ans = Integer.MIN_VALUE;
		for (int from = 0; from < n; from++) {
			int curMin = Integer.MAX_VALUE;
			for (int to = 0; to < n; to++) {
				int curVal = getValue(from, from, to, to);
				int add = cost[from];
				if (from != to) {
					add -= cost[to];
				}
				curVal += add;
				curMin = Math.min(curMin, curVal);
				
//				System.err.println(from + " " + to + " " + curVal);
			}
			System.err.println("min " + from + " " +curMin);
			ans = Math.max(curMin, ans);
		}
		out.println(ans);

	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Willow().run();
	}
}
