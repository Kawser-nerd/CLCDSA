import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int k = in.nextInt();
			double[] p = new double[n];
			for (int i = 0; i < n; i++) {
				p[i] = in.nextDouble();
			}
			Arrays.sort(p);
			double[] np = new double[k];
			double res = 0.0;
			for (int left = 0; left <= n; left++) {
				int right = k - left;
				if (right >= 0) {
					for (int i = 0; i < left; i++) {
						np[i] = p[i];
					}
					for (int i = 0; i < right; i++) {
						np[k - i - 1] = p[n - 1 - i];
					}
					double[] dp = new double[k + 1];
					dp[0] = 1;
					for (int i = 0; i < k; i++) {
						double[] ndp = new double[k + 1];
						for (int j = 0; j <= k; j++) {
							ndp[j] += dp[j] * (1 - np[i]);
							if (j + 1 <= k) {
								ndp[j + 1] += dp[j] * np[i];
							}
						}
						dp = ndp;
					}
					res = Math.max(res, dp[k / 2]);
				}
			}
			// double res = 0.0;
			// for (int mask = 0; mask < 1 << n; mask++) {
			// if (Integer.bitCount(mask) == k) {
			// double[] dp = new double[k + 1];
			// dp[0] = 1;
			// for (int i = 0; i < n; i++) {
			// if (((1 << i) & mask) != 0) {
			// double[] ndp = new double[k + 1];
			// for (int j = 0; j <= k; j++) {
			// ndp[j] += dp[j] * (1 - p[i]);
			// if (j + 1 <= k) {
			// ndp[j + 1] += dp[j] * p[i];
			// }
			// }
			// dp = ndp;
			// }
			// }
			// res = Math.max(res, dp[k / 2]);
			// }
			// }
			out.println(res);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

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
		new B().run();
	}
}