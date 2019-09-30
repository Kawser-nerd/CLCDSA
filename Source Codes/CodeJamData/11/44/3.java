import java.io.*;
import java.util.*;

public class D {

	int n;
	boolean[][] e;

	int[][] edgesList;
	int[] dp;
	int[][] to;
	int[] level;
	int[] d;

	int[] getList(boolean[] e) {
		int cnt = 0;
		for (boolean b : e) {
			if (b)
				cnt++;
		}
		int[] res = new int[cnt];
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (e[i])
				res[cnt++] = i;
		}
		return res;
	}

	private void solve() throws IOException {
		n = nextInt();
		e = new boolean[n][n];
		int wormholes = nextInt();
		for (int i = 0; i < wormholes; i++) {
			int x = nextInt(), y = nextInt();
			e[x][y] = e[y][x] = true;
		}
		edgesList = new int[n][];
		for (int i = 0; i < n; i++) {
			edgesList[i] = getList(e[i]);
		}
		d = new int[n];
		Arrays.fill(d, -1);
		d[0] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0);

		bfs: while (!q.isEmpty()) {
			int u = q.poll();
			for (int v : edgesList[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.add(v);
					if (v == 1)
						break bfs;
				}
			}
		}

		useful = new int[n];
		useful[1] = 1;
		dfs(0);
		to = new int[n][];
		for (int i = 0; i < n; i++) {
			if (d[i] == -1)
				continue;
			ArrayList<Integer> ok = new ArrayList<Integer>();
			for (int j = 0; j < n; j++) {
				if (e[i][j] && d[j] == d[i] + 1 && j != 1 && useful[j] == 1) {
					ok.add(j);
				}
			}
			to[i] = toArray(ok);
		}
		level = new int[n];
		Arrays.fill(level, Integer.MAX_VALUE);
		for (int i = 0; i < n; i++) {
			for (int j : edgesList[i]) {
				level[i] = Math.min(level[i], d[j]);
			}
		}

		dp2 = new int[n][n];
		for (int[] x : dp2) {
			Arrays.fill(x, -1);
		}
		out.println((d[1] - 1) + " " + getAnswer());
		// for (int i = 0; i < n; i++) {
		// System.out.println(i + " " + d[i] + " " + useful[i]);
		// }

	}

	int[] useful;

	void dfs(int u) {
		if (useful[u] != 0)
			return;
		useful[u] = -1;
		for (int v : edgesList[u]) {
			if (d[v] != d[u] + 1)
				continue;
			dfs(v);
			if (useful[v] == 1) {
				useful[u] = 1;
			}
		}
	}

	int[][] dp2;

	int getAnswer() {
		if (d[1] == 1) {
			return edgesList[0].length;
		}
		int res = 0;
		for (int i : to[0]) {
			res = Math.max(res, get1(0, i));
			// System.out.println(i + " " + get1(0, i));
		}
		return res;
	}

	int get1(int u, int v) {
		if (dp2[u][v] != -1)
			return dp2[u][v];
		int res = 0;
		int beatUnotV = edgesList[u].length - 1;
		for (int i : edgesList[u]) {
			if (e[v][i])
				beatUnotV--;
		}
		if (to[v].length == 0) {
			if (!e[v][1])
				throw new AssertionError();
			return dp2[u][v] = edgesList[v].length - 1 + beatUnotV;
		}
		for (int w : to[v]) {
			int cnt = 0;
			boolean[] edg = e[u];
			for (int x : edgesList[w]) {
				if (edg[x])
					cnt++;
			}
			int cur = get1(v, w) - cnt + beatUnotV;
			res = Math.max(res, cur);
		}
		return dp2[u][v] = res;
	}

	static int[] toArray(ArrayList<Integer> list) {
		int[] res = new int[list.size()];
		for (int i = 0; i < res.length; i++) {
			res[i] = list.get(i);
		}
		return res;
	}

	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "D-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
				System.out.println(i + "/" + T + " done");
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line, " ,");
		}
		return st.nextToken();
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