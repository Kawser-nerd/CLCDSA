import java.io.*;
import java.util.*;

public class CrimeHouse {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		char[] type = new char[n];
		int[] id = new int[n];
		for (int i = 0; i < n; i++) {
			type[i] = in.nextToken().charAt(0);
			id[i] = in.nextInt();
		}

		final int INF = Integer.MAX_VALUE / 4;
		int[] cost = new int[1 << n];
		cost[0] = 0;
		for (int i = 1; i < 1 << n; i++) {
			char lastType = ' ';
			int curId = 0;

			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) != 0) {
					if (lastType == type[j]) {
						cost[i] = INF;
						break;
					}
					lastType = type[j];
					if (id[j] != 0 && curId != 0 && id[j] != curId) {
						cost[i] = INF;
						break;
					}
					if (id[j] != 0) {
						curId = id[j];
					}
				}
			}

			if (cost[i] != INF) {
				cost[i] = lastType == 'E' ? 1 : 0;
			}

			if (cost[i] != INF && curId != 0) {
				for (int j = 0; j < n; j++) {
					if ((i & (1 << j)) == 0) {
						if (id[j] == curId) {
							cost[i] = INF;
						}
					}
				}
			}
		}
		
		
		int[] dp = new int[1 << n];
		Arrays.fill(dp, INF);
		dp[0] = 0;
		for (int mask = 1; mask < 1 << n; mask++) {
			for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
				dp[mask] = Math.min(dp[mask], dp[mask ^ submask] + cost[submask]);
			}
		}

		if (dp[(1 << n) - 1] == INF) {
			out.println("CRIME TIME");
		} else {
			out.println(dp[(1 << n) - 1]);
		}
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
		new CrimeHouse().run();
	}
}
