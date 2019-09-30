import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	int v1 = -1, v2 = -1;

	int[][] cnt;
	int[] color;
	int[] par;

	void dfs(int v, int p, int col) {
		cnt[v][col]++;
		color[v] = col;
		par[v] = p;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			if (color[u] != -1) {
				v1 = v;
				v2 = u;
			} else {
				dfs(u, v, col ^ 1);
				cnt[v][0] += cnt[u][0];
				cnt[v][1] += cnt[u][1];
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		cnt = new int[n][2];
		color = new int[n];
		par = new int[n];
		Arrays.fill(color, -1);
		dfs(0, -1, 0);

		long ans = 0;

		if (m == n - 1) {
			if (cnt[0][0] != cnt[0][1]) {
				ans = -1;
			} else {
				for (int i = 1; i < n; i++) {
					ans += Math.abs(cnt[i][0] - cnt[i][1]);
				}
			}
		} else if (color[v1] == color[v2]) {
			if (n % 2 == 1) {
				ans = -1;
			} else {
				int cv = color[v1];
				int delta = (cnt[0][cv ^ 1] - cnt[0][cv]) / 2;
				for (int v = v1; v != -1; v = par[v]) {
					cnt[v][cv] += delta;
				}
				for (int v = v2; v != -1; v = par[v]) {
					cnt[v][cv] += delta;
				}
				ans += Math.abs(delta);
				for (int i = 1; i < n; i++) {
					ans += Math.abs(cnt[i][0] - cnt[i][1]);
				}
			}
		} else {
			if (cnt[0][0] != cnt[0][1]) {
				ans = -1;
			} else {
				for (int i = 1; i < n; i++) {
					ans += Math.abs(cnt[i][0] - cnt[i][1]);
				}

				List<Integer> all = new ArrayList<>();
				for (int i = v2; i != v1; i = par[i]) {
					all.add(cnt[i][0] - cnt[i][1]);
					ans -= Math.abs(cnt[i][0] - cnt[i][1]);
				}

				all.add(0);
				
//				System.err.println(all);
				
				Collections.sort(all);
				int mid = all.get(all.size() / 2);
				for (int x : all) {
					ans += Math.abs(mid - x);
				}
			}
		}

		out.println(ans);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		Thread t = new Thread(null, () -> {
			try {
				solve();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}, "lul", 1 << 26);
		t.start();
		try {
			t.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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