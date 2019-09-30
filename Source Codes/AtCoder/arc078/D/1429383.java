import java.util.*;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();

		int[][] a = new int[n][n];
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1, cost = in.nextInt();
			a[from][to] = a[to][from] = cost;
		}

		int[] cost = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			for (int x = 0; x < n; x++) {
				for (int y = x + 1; y < n; y++) {
					if ((i & (1 << x)) != 0 && (i & (1 << y)) != 0) {
						cost[i] += a[x][y];
					}
				}
			}
		}
		
		int[][] dp = new int[n][1 << n];
		int INF = Integer.MIN_VALUE / 2;
		for (int[] i : dp) {
			Arrays.fill(i, INF);
		}
		for (int mask = 0; mask < 1 << n; mask++) {
			if ((mask & 1) != 0 && (mask & (1 << (n - 1))) == 0) {
				dp[0][mask] = cost[mask];
			}
		}
		
		int[][] bits = new int[1 << n][];
		for (int i = 0; i < 1 << n; i++) {
			bits[i] = new int[Integer.bitCount(i)];
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) != 0) {
					bits[i][tmp++] = j;
				}
			}
		}
		
		for (int mask = 1; mask < 1 << n; mask++) {
			for (int last = 0; last < n; last++) {
				if ((mask & (1 << last)) == 0) {
					continue;
				}
				int mx = INF;
				int andMask = mask ^ (1 << last);
				for (int submask = andMask; submask > 0; submask = (submask - 1) & andMask) {
					for (int prevLast : bits[submask]) {
						if ((submask & (1 << prevLast)) == 0) {
							continue;
						}
						if (a[last][prevLast] == 0) {
							continue;
						}
						
						int newCost = dp[prevLast][submask] + a[last][prevLast] + cost[mask ^ submask];
						if (newCost > mx) {
							mx = newCost;
						}
					}
				}
				dp[last][mask] = Math.max(dp[last][mask], mx);
			}
		}
		
		out.println(cost[(1 << n) - 1] - dp[n - 1][(1 << n) - 1]);
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
}