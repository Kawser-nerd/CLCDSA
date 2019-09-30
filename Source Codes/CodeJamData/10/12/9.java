package q1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final int INF = Integer.MAX_VALUE / 2;
	private static final String TASKNAME = "b";

	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			final int D = nextInt();
			final int I = nextInt();
			final int M = nextInt();
			final int n = nextInt();
			final int[] a = new int[n];
			for (int i = 0; i < a.length; ++i) {
				a[i] = nextInt();
			}

			final int[][] dp = new int[n][256];
			for (int[] aa : dp) {
				Arrays.fill(aa, INF);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < 256; ++j) {
					dp[i][j] = i * D + Math.abs(j - a[i]);
				}
			}

			int answer = n * D;
			for (int i = 0; i < n - 1; ++i) {
				for (int t = 0; t < 256; ++t) {
					for (int j = 0; j < 256; ++j) {
						if (dp[i][j] == INF) {
							continue;
						}
						for (int k = Math.max(j - M, 0); k < Math.min(256, j + M + 1); ++k) {
//							if (Math.abs(j - k) > M) {
//								continue;
//							}
							final int tt = dp[i][j] + I;
							if (dp[i][k] > tt) {
								dp[i][k] = tt;
							}
						}
					}
				}
				for (int j = 0; j < 256; ++j) {
					if (dp[i][j] == INF) {
						continue;
					}
					dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + D);
					final int upper = Math.min(256, j + M + 1);
					for (int k = Math.max(j - M, 0); k < upper; ++k) {
						int add = a[i + 1] - k;
						if (add < 0) {
							add *= -1;
						}
						final int tt = dp[i][j] + add;
						if (dp[i + 1][k] > tt) {
							dp[i + 1][k] = tt;
						}
//						dp[i + 1][k] = Math.min(dp[i + 1][k], tt);
					}
				}
			}
			for (int i = 0; i < 256; ++i) {
				answer = Math.min(answer, dp[n - 1][i]);
			}
			
//			for (int i = 0; i < n; ++i) {
//				for (int j = 0; j < 10; ++j) {
//					System.err.print(dp[i][j] + " ");
//				}
//				System.err.println();
//			}
//			System.err.println();

			printf("Case #%d: %d\n", test, answer);
			writer.flush();
		}
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(TASKNAME
					+ ".out")));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			throw new AssertionError(e);
		}
	}

	private void print(final Object o) {
		writer.print(o);
	}

	private void println(final Object o) {
		writer.println(o);
	}

	private void printf(final String format, final Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws InterruptedException {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		final Thread thread = new Thread(null, new Main(), "", 1 << 23);
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}
}
