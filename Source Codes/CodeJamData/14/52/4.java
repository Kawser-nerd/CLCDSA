import java.io.*;
import java.util.*;

public class LastHit {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int p = in.nextInt(), q = in.nextInt(), n = in.nextInt();
		int[] h = new int[n], g = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = in.nextInt();
			g[i] = in.nextInt();
		}

		int maxLeft = 10 * n + 1;
		int[][] dp = new int[n + 1][maxLeft + 1];

		final int INF = Integer.MIN_VALUE;
		for (int[] i : dp) {
			Arrays.fill(i, INF);
		}

		dp[0][1] = 0;

		int best = INF;
		for (int i = 0; i < n; i++) {
			int needTower = (h[i] + q - 1) / q;

			for (int j = 0; j <= maxLeft; j++) {
				if (dp[i][j] == INF) {
					continue;
				}
				
				dp[i + 1][j + needTower] = Math.max(dp[i + 1][j + needTower], dp[i][j]);
				
				int rmnHp = h[i] - (needTower - 1) * q;
				int shots = (rmnHp + p - 1) / p;
				
				int newShots = j + needTower - 1 - shots;
				if (newShots < 0) {
					continue;
				}
				
				dp[i + 1][newShots] = Math.max(dp[i + 1][newShots], dp[i][j] + g[i]);
			}
		}
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= maxLeft; j++) {
				best = Math.max(best, dp[i][j]);
			}
		}
		out.println(best);

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
		new LastHit().run();
	}
}
