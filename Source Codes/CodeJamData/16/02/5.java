import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	int get(char c) {
		return c == '+' ? 0 : 1;
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			String s = in.next();
			int n = s.length();
			int[][] dp = new int[2][n + 1];
			Arrays.fill(dp[0], Integer.MAX_VALUE / 2);
			Arrays.fill(dp[1], Integer.MAX_VALUE / 2);
			dp[0][0] = dp[1][0] = 0;
			for (int len = 1; len <= n; len++) {
				for (int it = 0; it < 2; it++) {
					for (int want = 0; want < 2; want++) {
						dp[want][len] = Math.min(dp[want][len],
								dp[1 - want][len] + 1);
						if (get(s.charAt(len - 1)) == want) {
							dp[want][len] = Math.min(dp[want][len],
									dp[want][len - 1]);
						}
					}
				}
			}
			out.println(dp[0][n]);
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