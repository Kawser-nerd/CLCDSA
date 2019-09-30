import java.util.*;
import java.io.*;

public class A {

	void solve() {
		int n = in.nextInt(), p = in.nextInt();
		int sum = 0;
		int[] g = new int[4];
		for (int i = 0; i < n; i++) {
			int gg = in.nextInt() % p;
			sum += gg;
			g[gg]++;
		}
		sum %= p;

		int[][][][] dp = new int[p][g[1] + 1][g[2] + 1][g[3] + 1];
//		int INF = Integer.MAX_VALUE / 3;
//		for (int[][][] i : dp) {
//			for (int[][] j : i) {
//				for (int[] k : j) {
//					Arrays.fill(k, INF);
//				}
//			}
//		}
		dp[0][0][0][0] = 1;

		for (int p1 = 0; p1 <= g[1]; p1++) {
			for (int p2 = 0; p2 <= g[2]; p2++) {
				for (int p3 = 0; p3 <= g[3]; p3++) {
					for (int m = 0; m < p; m++) {
							int val = dp[m][p1][p2][p3];
							if (p1 + 1 <= g[1]) {
								int newM = (m + 1) % p;
								dp[newM][p1 + 1][p2][p3] = Math.max(dp[newM][p1 + 1][p2][p3],
										val + (newM == 0 ? 1 : 0));
							}
							if (p2 + 1 <= g[2]) {
								int newM = (m + 2) % p;
								dp[newM][p1][p2 + 1][p3] = Math.max(dp[newM][p1][p2 + 1][p3],
										val + (newM == 0 ? 1 : 0));
							}
							if (p3 + 1 <= g[3]) {
								int newM = (m + 3) % p;
								dp[newM][p1][p2][p3 + 1] = Math.max(dp[newM][p1][p2][p3 + 1],
										val + (newM == 0 ? 1 : 0));
							}
						}
					}
			}
		}
		int ans = dp[sum][g[1]][g[2]][g[3]] + g[0];
		if (sum == 0) {
			ans--;
		}
		out.println(ans);
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner("input.txt");
		try {
			out = new PrintWriter("output.txt");
		} catch (FileNotFoundException e) {
		}
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			long startTime = System.currentTimeMillis();
			out.printf("Case #%d: ", i + 1);
			solve();
			System.err.printf("Test #%d solved in %d ms\n", i + 1, System.currentTimeMillis() - startTime);
		}
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
		new A().run();
	}
}
