import java.io.*;
import java.util.*;

public class Main {

	static final int INF = Integer.MAX_VALUE / 10;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	int brute(String s) {
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], INF);
			d[i][i] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j : g[i]) {
				d[i][j] = 1;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
		}

		// System.err.println(Arrays.deepToString(d));

		HashSet<Integer> ans = new HashSet<>();
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '0') {
				continue;
			}

			for (int dist = 0; dist < n; dist++) {
				int mask = 0;
				for (int j = 0; j < n; j++) {
					if (d[i][j] <= dist) {
						mask |= 1 << j;
					}
				}
				ans.add(mask);
			}

		}
		return ans.size();
	}

	int n;

	int[][] bfs(int v) {
		int[] d = new int[n];
		int[] par = new int[n];
		Arrays.fill(d, INF);
		par[v] = v;

		int[] que = new int[n];
		int head = 0, tail = 0;

		que[tail++] = v;
		d[v] = 0;

		while (head < tail) {
			v = que[head++];
			for (int u : g[v]) {
				if (d[u] > d[v] + 1) {
					d[u] = d[v] + 1;
					que[tail++] = u;
					par[u] = v;
				}
			}
		}

		return new int[][] { d, par };
	}

	int[] findCentre() {
		int[][] info = bfs(0);

		int v = 0;
		for (int i = 0; i < n; i++) {
			if (info[0][i] > info[0][v]) {
				v = i;
			}
		}

		info = bfs(v);

		v = 0;
		for (int i = 0; i < n; i++) {
			if (info[0][i] > info[0][v]) {
				v = i;
			}
		}

		int diam = info[0][v];
		for (int i = 0; i < diam / 2; i++) {
			v = info[1][v];
		}

		if (diam % 2 == 0) {
			return new int[] { v, diam / 2 };
		} else {
			return new int[] { v, info[1][v], diam / 2 + 1 };
		}
	}

	long solve(int[] vs, int[] us, String s) {
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v = vs[i];
			int u = us[i];
			g[v].add(u);
			g[u].add(v);
		}

		int[] tmp = findCentre();

		int[] furth = new int[n];
		int[] par = new int[n];

		int[] que = new int[n];
		int head = 0, tail = 0;
		Arrays.fill(furth, -1);

		for (int i = 0; i < tmp.length - 1; i++) {
			que[tail++] = tmp[i];
			furth[tmp[i]] = tmp[tmp.length - 1];
		}

		par[tmp[0]] = tmp[0];
		if (tmp.length == 3) {
			par[tmp[1]] = tmp[0];
		}

		while (head < tail) {
			int v = que[head++];
			for (int u : g[v]) {
				if (furth[u] == -1) {
					furth[u] = furth[v] + 1;
					par[u] = v;
					que[tail++] = u;
				}
			}
		}

		int[] depth = new int[n];
		int[] high = new int[n];
		int[] low = new int[n];

		long ans = 1;

		for (int i = n - 1; i >= 0; i--) {
			int v = que[i];

			low[v] = s.charAt(v) == '1' ? 0 : INF;

			for (int u : g[v]) {
				if (u == par[v]) {
					continue;
				}

				depth[v] = Math.max(depth[v], depth[u] + 1);
				low[v] = Math.min(low[v], low[u] - 1);
			}

			high[v] = Math.min(depth[v] + 1, furth[v] - 1);
			ans += Math.max(high[v] - low[v] + 1, 0);
			low[v] = Math.max(low[v], high[v] + 1);
			
			if (low[v] == furth[v]) {
				low[v] = INF;
			}
		}
		
//		if (ans != brute(s)) {
//			throw new AssertionError(Arrays.toString(g) + " " + s);
//		}
		
		return ans;
	}

	void submit() throws IOException {
		n = nextInt();
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
		}
		String s = nextToken();
		out.println(solve(vs, us, s));
	}

	static final Random rng = new Random();

	void stress(int n) {
		this.n = n;
		int[] vs = new int[n - 1];
		int[] us = new int[n - 1];
		char[] buf = new char[n];

		for (int i = 0; i < n - 1; i++) {
			vs[i] = i + 1;
			us[i] = rng.nextInt(i + 1);
		}

		for (int i = 0; i < n; i++) {
			buf[i] = rng.nextBoolean() ? '0' : '1';
		}

		buf[rng.nextInt(n)] = '1';

		solve(vs, us, new String(buf));

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// solve();

		 submit();

//		for (int i = 0; i < Integer.MAX_VALUE; i++) {
//			System.err.println(i);
//			stress(25);
//		}

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