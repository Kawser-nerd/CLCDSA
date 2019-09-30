import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt(), r = in.nextInt(), p = in.nextInt(), s = in
				.nextInt();
		final int S = 0, R = 1, P = 2;
		String[][][][] dp = new String[n + 1][3][r + 1][p + 1];
		if (s > 0)
			dp[0][S][0][0] = "S";
		if (r > 0)
			dp[0][R][1][0] = "R";
		if (p > 0)
			dp[0][P][0][1] = "P";
		for (int i = 0; i < n; i++) {
			for (int cr1 = 0; cr1 <= r; cr1++) {
				for (int cp1 = 0; cp1 <= p; cp1++) {
					for (int left = 0; left < 3; left++) {
						if (dp[i][left][cr1][cp1] != null) {
							for (int cr2 = 0; cr2 <= r - cr1; cr2++) {
								for (int cp2 = 0; cp2 <= p - cp1; cp2++) {
									for (int right = 0; right < 3; right++) {
										if (left != right) {
											if (dp[i][right][cr2][cp2] != null) {
												String str = dp[i][left][cr1][cp1]
														+ dp[i][right][cr2][cp2];
												int win = 0;
												if (left == S) {
													win = (right == P) ? left : right;
												} else if (left == P) {
													win = (right == R) ? left : right;
												} else if (left == R) {
													win = (right == S) ? left : right;
												}
												if (dp[i + 1][win][cr1 + cr2][cp1
														+ cp2] == null
														|| str.compareTo(dp[i + 1][win][cr1
																+ cr2][cp1
																+ cp2]) < 0) {
													dp[i + 1][win][cr1 + cr2][cp1
															+ cp2] = str;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		String ans = null;
		for (int win = 0; win < 3; win++) {
			if (dp[n][win][r][p] != null) {
				if (ans == null || dp[n][win][r][p].compareTo(ans) < 0) {
					ans = dp[n][win][r][p];
				}
			}
		}
		if (ans == null) {
			out.println("IMPOSSIBLE");
		} else {
			out.println(ans);
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
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

	public static void main(String[] arg) {
		new B().run();
	}
}