import java.util.*;
import java.io.*;

public class Main {

	List<Integer>[] tree;
	int[] w;
	int INF = Integer.MAX_VALUE / 3;
	int[][] dp;

	int MAX = 6000;
	int[] buf = new int[MAX + 1];
	int[] buf2 = new int[MAX + 1];

	void dfs(int u) {
		for (int v : tree[u]) {
			dfs(v);
		}

		for (int col = 0; col < 2; col++) {
			Arrays.fill(buf, INF);
			buf[0] = 0;
			for (int v : tree[u]) {
				int val1 = dp[v][col];
				int val2 = dp[v][col ^ 1];
				Arrays.fill(buf2, INF);

				for (int i = 0; i <= MAX; i++) {
					// pairs (w[v], val2), (val1, w[v])
					if (i >= w[v]) {
						buf2[i] = Math.min(buf[i - w[v]] + val2, buf2[i]);
					}
					if (i >= val1) {
						buf2[i] = Math.min(buf[i - val1] + w[v], buf2[i]);
					}
				}
				System.arraycopy(buf2, 0, buf, 0, buf.length);
			}

			int min = INF;
			for (int i = 0; i <= w[u]; i++) {
				min = Math.min(min, buf[i]);
			}
			dp[u][col] = min;
		}
	}

	void solve() {
		int n = in.nextInt();
		tree = new List[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			tree[in.nextInt() - 1].add(i);
		}
		w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
		}
		dp = new int[n][2];
		for (int[] i : dp) {
			Arrays.fill(i, INF);
		}
		dfs(0);
		if (dp[0][0] < INF || dp[0][1] < INF) {
			out.println("POSSIBLE");
		} else {
			out.println("IMPOSSIBLE");
		}
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.