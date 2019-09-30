import java.io.*;
import java.util.*;

public class CopyOfA {
	FastScanner in;
	PrintWriter out;

	int[] answers;

	void solve() {
		int tc = in.nextInt();
		Random rnd = new Random(123);
		long START = System.currentTimeMillis();
		answers = new int[tc];
		String[] ss = new String[tc];
		for (int t = 0; t < tc; t++) {
			ss[t] = in.next();
		}
		Thread[] all = new Thread[tc];
		for (int t = 0; t < tc; t++) {
			final int tmp = t;
			Runnable r = new Runnable() {

				@Override
				public void run() {
					int n = ss[tmp].length();
					int[] a = new int[n];
					for (int i = 0; i < n; i++) {
						a[i] = ss[tmp].charAt(i) - '0';
					}
					final int MAX = 20 * 9 + 1;
					int[][] dp = new int[MAX][n];
					int[][] last = new int[10][n];
					for (int i = 1; i < 10; i++) {
						for (int j = 0; j < n; j++) {
							last[i][j] = (j == 0 ? -1 : last[i][j - 1]);
							if (a[j] == i) {
								last[i][j] = j;
							}
						}
					}
					for (int i = 0; i < n; i++) {
						dp[0][i] = i;
					}
					for (int cost = 1; cost < MAX; cost++) {
						for (int start = 0; start < n; start++) {
							int res = start;
							for (int use = 1; use < 10; use++) {
								if (cost - use < 0) {
									continue;
								}
								int look = dp[cost - use][start];
								if (look == n) {
									res = n;
								} else {
									int usePos = last[use][look];
									if (usePos >= start) {
										if (usePos == n - 1) {
											res = n;
										} else {
											res = Math.max(res,
													dp[cost - use][usePos + 1]);
										}
									}
								}
							}
							dp[cost][start] = res;
						}
					}
					int result = Integer.MAX_VALUE;
					for (int cost = 0; cost < MAX; cost++) {
						if (dp[cost][0] == n) {
							result = cost;
							break;
						}
					}
					if (result == Integer.MAX_VALUE) {
						throw new AssertionError();
					}
					answers[tmp] = result;
					System.err.println(tmp + " done!");
				}
			};
			all[t] = new Thread(r);
			// all[t].start();
		}
		final int X = 7;
		for (int from = 0; from < tc; from += X) {
			int to = Math.min(tc, from + X);
			for (int t = from; t < to; t++) {
				all[t].start();
			}
			for (int t = from; t < to; t++) {
				try {
					all[t].join();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			System.err.println(System.currentTimeMillis() - START);
		}
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			out.println(answers[t]);
			System.err.println((t + 1) + "/" + tc + " done");
		}
		System.err.println(System.currentTimeMillis() - START);
	}

	void run() {
		try {
			in = new FastScanner(new File("A-large.in"));
			out = new PrintWriter(new File("A.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CopyOfA().run();
	}
}